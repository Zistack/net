void
T::processFrames (IO::Blocking::InputStream::T & input_stream,
    Shutdown::Signal::T & input_shutdown_signal,
    IO::CancelSignal::T & input_timeout_signal)
{
	::Protocol::eventLoop (this->exception_store,
	    input_stream,
	    input_shutdown_signal,
	    &T::processEvent,
	    this,
	    input_stream,
	    input_timeout_signal);
}