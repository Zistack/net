template <typename ServerProtocol>
void
T <ServerProtocol>::accept
(
	Socket::T & server_socket,
	Thread::Nursery::T & nursery
)
{
	auto connection_protocol = this -> server_protocol . make ();

	connection_protocol -> prime ();

	std::unique_ptr <Connection::Socket::T> connection_socket =
		server_socket . accept ();

	nursery.add
	(
		* connection_protocol,
		[
			this,
			connection_protocol (std::move (connection_protocol)),
			connection_socket (std::move (connection_socket))
		] ()
		{
			try
			{
				IO::CancelSignal::T timeout_signal;

				try
				{
					{
						Thread::Timer::T handshake_timer
						(
							this -> config . getTimeout (),
							& IO::CancelSignal::T::cancel,
							& timeout_signal
						);
						connection_socket -> handshake (timeout_signal);
					}
					timeout_signal . clear ();
				}
				catch (Failure::CancelException::T)
				{
					throw Failure::ResourceError::T
					(
						"TLS handshake timed out\n"
					);
				}

				ConnectionSocket::Reciever::T input_stream =
					connection_socket -> reciever ();
				ConnectionSocket::Sender::T output_stream =
					connection_socket -> sender ();

				connection_protocol -> run (input_stream, output_stream);

				try
				{
					{
						Thread::Timer::T close_timer
						(
							this -> config . getTimeout (),
							& IO::CancelSignal::T::cancel,
							& timeout_signal
						);
						connection_socket -> close (timeout_signal);
					}
					timeout_signal . clear ();
				}
				catch (Failure::CancelException::T)
				{
					throw Failure::ResourceError::T ("TLS close timed out\n");
				}
			}
			catch (...)
			{
				// Log it, which for now means ignore it.
			}
		}
	);
}
