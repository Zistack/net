template <typename Protocol>
void
T<Protocol>::run ()
{
	Socket::T client_socket (this->config);

	IO::CancelSignal::T timeout_signal;

	try
	{
		{
			Thread::Timer::T handshake_timer (this->config.getTimeout (),
			    &IO::CancelSignal::T::cancel,
			    &timeout_signal);
			client_socket.handshake (timeout_signal);
		}
		timeout_signal.clear ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("TLS handshake timed out\n");
	}

	ConnectionSocket::Reciever::T input_stream = client_socket.reciever ();
	ConnectionSocket::Sender::T output_stream = client_socket.sender ();

	this->protocol.run (input_stream, output_stream);

	try
	{
		{
			Thread::Timer::T close_timer (this->config.getTimeout (),
			    &IO::CancelSignal::T::cancel,
			    &timeout_signal);
			client_socket.close (timeout_signal);
		}
		timeout_signal.clear ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("TLS close timed out\n");
	}
}
