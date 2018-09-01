void
T::run ()
{
	const std::string message_prefix = "TCP::Server::Connection::T::run\n";

	try
	{
		this->protocol.init (
		    this->socket->input_stream, this->socket->output_stream);

		Failure::ExceptionStore::T exception_store;

		try
		{
			while (true)
			{
				try
				{
					IO::Util::wait (*this->socket->input_stream, this->signal);
				}
				catch (const Failure::CancelError::T & e)
				{
					break;
				}

				try
				{
					this->protocol.event ();
				}
				catch (const IO::EOF::T & e)
				{
					break;
				}
			}
		}
		catch (const Failure::Throwable::T & e)
		{
			exception_store.store (e);
		}

		try
		{
			this->protocol.clean ();
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
