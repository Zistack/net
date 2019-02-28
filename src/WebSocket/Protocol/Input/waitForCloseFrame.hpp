void
T::waitForCloseFrame (IO::Blocking::InputStream::T & input_stream,
    IO::CancelSignal::T & input_timeout_signal)
{
	Shutdown::Signal::T wait_shutdown_signal;

	SuppressingScope::T wait_scope (
	    wait_shutdown_signal, this->exception_store);

	Thread::Timer::T (this->close_timeout,
	    &Shutdown::Signal::T::cancel,
	    wait_shutdown_signal);

	::Protocol::eventLoop (this->exception_store,
	    input_stream,
	    wait_shutdown_signal,
	    &T::waitEvent,
	    this,
	    input_stream,
	    input_timeout_signal);
}
