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
			Thread::Timer::T input_timer (this->input_timeout,
			    [this]() { this->input_timeout_signal.send (); });
			response_delay.value ().set (this->readResponse (input_stream));
		}
		this->input_timeout_signal.recieve ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::Error::T ("Reading response timed out\n");
	}
}
