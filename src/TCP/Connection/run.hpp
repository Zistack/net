void
T::run ()
{
	const std::string message_prefix = "TCP::Connection::run\n";

	try
	{
		IO::EPoll::T epoll;

		epoll.add (this->signal);
		epoll.add (this->socket->input_stream);

		this->protocol->init (
		    this->socket->input_stream, this->socket->output_stream);

		Failure::ExceptionStore::T exception_store;

		try
		{
			while (true)
			{
				IO::Interface::Watchable::T * ready_stream = epoll.wait ();

				if (ready_stream == this->socket->input_stream)
					this->protocol->event ();
				else if (ready_stream == this->signal)
					break;
			}
		}
		catch (const Failure::Throwable::T & e)
		{
			exception_store.store (e);
		}

		try
		{
			this->protocol->clean ();
		}
		catch (const Failure::Throwable::T & e)
		{
			exception_store.store (e);
		}

		try
		{
			this->socket->shutdown (
			    IO::Socket::Direction::READ | IO::Socket::Direction::WRITE);
		}
		catch (const Failure::Throwable::T & e)
		{
			exception_store.store (e);
		}

		exception_store.poll ();
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
