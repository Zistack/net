void
T::run ()
{
	Failure::ExceptionStore::T exception_store;
	Thread::Nursery::T nursery (exception_store);

	while (true)
	{
		try
		{
			IO::Util::wait (this->server_socket, this->shutdown_signal);
		}
		catch (Failure::CancelException::T)
		{
			break;
		}
		catch (...)
		{
			exception_store.store (std::current_exception ());
			break;
		}

		IO::Socket::T * socket;

		try
		{
			socket = server_socket->accept ();
		}
		catch (...)
		{
			exception_store.store (std::current_exception ());
			break;
		}

		IO::Interface::Protocol::T * protocol;

		try
		{
			protocol = this->protocol_factory.make ();
		}
		catch (...)
		{
			exception_store.store (std::current_exception ());
			break;
		}

		Connection::T * connection;

		try
		{
			connection = new Connection::T (protocol, socket, this->log);
		}
		catch (...)
		{
			exception_store.store (std::current_exception ());
			delete protocol;
			break;
		}

		nursery.add ([connection]() { connection->run (); },
		    [protocol, socket, connection]() {
			    delete connection;
			    delete protocol;
			    delete socket;
		    },
		    [connection]() { connection->stop (); });
	}

	nursery.cancel ();

	nursery.join ();

	exception_store.poll ();
}
