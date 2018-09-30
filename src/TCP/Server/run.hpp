void
T::run ()
{
	const std::string message_prefix = "TCP::Server::T::run\n";

	try
	{
		Failure::ExceptionStore::T exception_store;

		IO::ServerSocket::T server_socket (
		    this->hostname, this->port, this->log);

		try
		{
			Thread::Nursery::T nursery;

			Protocol::eventLoop (exception_store,
			    server_socket,
			    this->shutdown_signal,
			    [this, &server_socket, &nursery]() {
				    IO::Socket::T * socket;

				    socket = new IO::Socket::T (&server_socket);
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
					        protocol->run (
					            socket->input_stream, socket->output_stream);
				        },
				        [protocol, socket]() {
					        delete protocol;
					        delete socket;
				        },
				        [protocol]() { protocol->stop (); });
			    });

			nursery.cancel ();
		}
		catch (...)
		{
			exception_store.store (std::current_exception ());
		}

		exception_store.poll ();
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
