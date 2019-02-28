void
T::processFrames (IO::Blocking::InputStream::T & input_stream,
    IO::CancelSignal::T & input_timeout_signal)
{
	::Protocol::eventLoop (this->exception_store,
	    input_stream,
	    this -> input_shutdown_signal,
	    &T::processEvent,
	    this,
	    input_stream,
	    input_timeout_signal);
}
