void
T::runProtocol ()
{
	const std::string message_prefix = "TLS::Adapter::runProtocol\n";

	try
	{
		this->protocol.init (this->socket_to_protocol->input_stream,
		    this->protocol_to_socket->output_stream);

		Failure::ExceptionStore::T exception_store;

		try
		{
			while (true)
			{
				try
				{
					IO::Util::wait (this->socket_to_protocol->input_stream,
					    *this->shutdown_signal);
				}
				catch (const Failure::CancelError::T & e)
				{
					break;
				}

				this->protocol.event ();
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

		exception_store.poll ();
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
