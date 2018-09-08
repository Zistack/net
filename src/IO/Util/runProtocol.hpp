void
runProtocol (Interface::Protocol::T * protocol,
    Failure::ExceptionStore::T & exception_store,
    Interface::NonblockingInputStream::T * input_stream,
    Interface::NonblockingOutputStream::T * output_stream,
    Signal::T * shutdown_signal)
{
	try
	{
		protocol->init (input_stream, output_stream);
	}
	catch (const Failure::Throwable::T & e)
	{
		exception_store.store (e);
		return;
	}

	try
	{
		while (true)
		{
			try
			{
				IO::Util::wait (input_stream, shutdown_signal);
			}
			catch (const Failure::CancelError::T & e)
			{
				break;
			}

			exception_store.poll ();

			try
			{
				protocol->event ();
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
		protocol->clean ();
	}
	catch (const Failure::Throwable::T & e)
	{
		exception_store.store (e);
	}
}
