void
T::run (IO::Interface::NonblockingInputStream::T & nonblocking_input_stream)
{
	SuppressingScope::T input_shutdown_scope (
	    std::move (this->input_shutdown_scope));

	IO::CancelSignal::T input_timeout_signal;
	IO::Blocking::InputStream::T input_stream (
	    nonblocking_input_stream, input_timeout_signal);

	try
	{
		this->processFrames (input_stream, input_timeout_signal);

		if (!this->close_message)
		{
			this->waitForCloseFrame (input_stream, input_timeout_signal);
		}
	}
	catch (...)
	{
		this->exception_store.store (std::current_exception ());
	}

	this->exception_store.pop ();
}
