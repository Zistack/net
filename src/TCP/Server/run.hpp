void
T::run ()
{
	const std::string message_prefix = "TCP::Server::run\n";

	try
	{
		IO::EPoll::T epoll;

		epoll.add (this->signal);
		epoll.add (this->server_socket);

		Failure::ExceptionStore::T exception_store;
		Thread::Nursery::T nursery (exception_store);

		while (true)
		{
			IO::Interface::Watchable::T * ready_stream = epoll.wait ();

			exception_store.poll ();

			if (ready_stream == this->server_socket)
			{
				IO::Socket::T * socket = NULL;

				try
				{
					socket = server_socket->accept ();
				}
				catch (const Failure::Throwable::T & e)
				{
					log->print (e.what ());
					continue;
				}

				nursery.add (&T::serve, this, socket);
			}
			else if (ready_stream == this->signal)
			{
				break;
			}
		}

		nursery.join ();
		exception_store.poll ();
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
