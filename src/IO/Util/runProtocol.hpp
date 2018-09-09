void
runProtocol (Interface::Protocol::T * protocol,
    Failure::ExceptionStore::T & exception_store,
    Interface::NonblockingInputStream::T * input_stream,
    Interface::NonblockingOutputStream::T * output_stream,
    Signal::T * shutdown_signal)
{
	try
	{
		protocol->init (input_stream, output_stream, exception_store, [=]() {
			shutdown_signal->send ();
		});
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
