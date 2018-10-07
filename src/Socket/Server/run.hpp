void
T::run ()
{
	const std::string message_prefix = "Socket::Server::T::run\n";

	try
	{
		Failure::ExceptionStore::T exception_store;

		IO::Interface::ServerSocket::T * server_socket = this->newSocket ();

		{
			Thread::Nursery::T nursery (&exception_store);

			Protocol::eventLoop (exception_store,
			    server_socket,
			    this->shutdown_signal,
			    [this, server_socket, &nursery]() {
				    IO::Interface::ClientSocket::T * socket;

				    socket = server_socket->accept ();
				    IO::Interface::Protocol::T * protocol;
				    try
				    {
					    protocol = this->protocol_factory->make ();
				    }
				    catch (...)
				    {
					    delete socket;
					    throw;
				    }

				    nursery.add (
				        [protocol, socket]() {
					        protocol->run (socket->inputStream (),
					            socket->outputStream ());
				        },
				        [protocol, socket]() {
					        delete protocol;
					        delete socket;
				        },
				        [protocol]() { protocol->stop (); });
			    });

			nursery.cancel ();
		}

		delete server_socket;

		exception_store.poll ();
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
