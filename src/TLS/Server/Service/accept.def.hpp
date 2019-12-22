template <typename ServerProtocol>
void
T <ServerProtocol>::accept
(
	Socket::T & server_socket,
	Thread::Nursery::Collection::T <true, ConnectionProtocol> & nursery
)
{
	auto connection_protocol = this -> m_server_protocol . make ();

	connection_protocol -> prime ();

	int tcp_connection_socket = server_socket . accept ();

	nursery . add
	(
		* connection_protocol,
		[
			this,
			tcp_connection_socket,
			connection_protocol (std::move (connection_protocol))
		] ()
		{
			try
			{
				Connection::Socket::T connection_socket
				(
					tcp_connection_socket,
					this -> m_config,
					this -> m_ciphers
				);

				connection_protocol -> run
				(
					connection_socket . reciever (),
					connection_socket . sender ()
				);
			}
			catch (...)
			{
				// Log it, which for now means ignore it.
			}
		}
	);
}
