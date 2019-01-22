void
T::input (Shutdown::Signal::T & input_shutdown_signal)
{
	IO::CancelSignal::T input_timeout_signal;
	IO::Blocking::InputStream::T input_stream (
	    *this->nonblocking_input_stream, input_timeout_signal);

	this->processFrames (
	    input_stream, input_shutdown_signal, input_timeout_signal);

	uint16_t status_code;

	{
		std::unique_lock<decltype (this->close_mutex)> close_lock (
		    this->close_mutex);
		status_code = this->status_code;
	}

	if (status_code < 1000)
	{
		this->waitForCloseFrame (input_stream, input_timeout_signal);
	}
}
