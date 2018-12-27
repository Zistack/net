template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::event (
    IO::Blocking::InputStream::T & input_stream)
{
	auto response_delay = this->response_queue.tryPop ();

	if (!response_delay)
	{
		throw Failure::Error::T ("Found response without matching request\n");
	}

	try
	{
		{
			Failure::CancelScope::T input_cancel_scope;
			Thread::Timer::T input_timer (this->config.input_timeout,
			    [&input_cancel_scope]() { input_cancel_scope.cancel (); });
			response_delay.value ().set (std::move (this->readResponse (
			    input_stream, this->input_cancel_signal, input_cancel_scope)));
		}
		this->input_cancel_signal.clear ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::Error::T ("Reading response timed out\n");
	}
}
