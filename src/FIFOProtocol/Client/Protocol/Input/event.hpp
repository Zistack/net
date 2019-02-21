template <typename ResponseType>
void
T<ResponseType>::event (IO::Blocking::InputStream::T & input_stream,
    IO::CancelSignal::T & input_cancel_signal)
{
	::Protocol::Delay::T<ResponseType> response_delay =
	    this->response_queue.pop ();

	try
	{
		{
			Failure::CancelScope::T input_cancel_scope;
			Thread::Timer::T input_timer (this->input_timeout,
			    &Failure::CancelScope::T::cancel,
			    &input_cancel_scope);
			response_delay.value ().set (std::move (this->readResponse (
			    input_stream, input_cancel_signal, input_cancel_scope)));
		}
		this->input_cancel_signal.clear ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::Error::T ("Reading response timed out\n");
	}
}
