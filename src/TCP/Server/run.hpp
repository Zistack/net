void
T::run ()
{
	Failure::ExceptionStore::T exception_store;
	Thread::Nursery::T nursery (exception_store);

	while (true)
	{
		try
		{
			IO::Util::wait (this->server_socket, this->signal);
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

		try
		{
			exception_store.poll ();
		}
		catch (...)
		{
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

		nursery.add (&T::serve, this, socket);
	}

	nursery.join ();

	exception_store.poll ();
}
