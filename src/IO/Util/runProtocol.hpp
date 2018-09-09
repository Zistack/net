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
	catch (...)
	{
		exception_store.store (std::current_exception ());
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
			catch (Failure::CancelException::T)
			{
				break;
			}

			exception_store.poll ();

			try
			{
				protocol->event ();
			}
			catch (IO::EOF::T)
			{
				break;
			}
		}
	}
	catch (...)
	{
		exception_store.store (std::current_exception ());
	}

	try
	{
		protocol->clean ();
	}
	catch (...)
	{
		exception_store.store (std::current_exception ());
	}
}
