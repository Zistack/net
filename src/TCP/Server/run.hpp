void
T::run ()
{
	const std::string message_prefix = "TCP::Server::run\n";

	try
	{
		Failure::ExceptionStore::T exception_store;
		Thread::Nursery::T nursery (exception_store);

		while (true)
		{
			try
			{
				IO::Util::wait (*this->server_socket, *this->signal);
			}
			catch (const Failure::CancelError::T & e)
			{
				break;
			}

			exception_store.poll ();

			IO::Socket::T * socket;

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

		nursery.join ();
		exception_store.poll ();
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
