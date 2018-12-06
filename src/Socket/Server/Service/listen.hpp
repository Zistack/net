void
T::listen (Thread::Nursery::T & nursery)
{
	const std::string message_prefix = "Socket::Server::Service::T::listen\n";

	Failure::ExceptionStore::T exception_store;

	{
		std::unique_ptr<IO::Interface::Server::Socket::T> server_socket (
		    std::move (this->server_socket));
		SuppressingScope::T<Shutdown::Signal::T> shutdown_signal_scope (
		    std::move (this->shutdown_signal_scope));

		Protocol::eventLoop (exception_store,
		    *server_socket,
		    this->shutdown_signal,
		    [this, &server_socket (*server_socket), &nursery]() {
			    std::unique_ptr<IO::Interface::Socket::T> connection_socket =
			        server_socket.accept ();

			    std::unique_ptr<IO::Interface::Protocol::T>
			        connection_protocol = this->server_protocol.make ();
			    IO::Interface::Protocol::T * connection_protocol_ptr =
			        connection_protocol.get ();

			    connection_protocol->prime (connection_socket->inputStream (),
			        connection_socket->outputStream ());

			    nursery.add (
			        [connection_socket (std::move (connection_socket)),
			            connection_protocol (
			                std::move (connection_protocol))]() {
				        try
				        {
					        connection_protocol->run ();
				        }
				        catch (const Failure::Error::T & e)
				        {
					        // Log it, which for now means ignore it.
				        }
			        },
			        connection_protocol_ptr);
		    });
	}

	try
	{
		exception_store.poll ();
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
