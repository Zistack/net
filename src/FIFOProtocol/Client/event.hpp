template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::event (
    IO::Blocking::InputStream::T & input_stream)
{
	ResponseType response;

	try
	{
		{
			Thread::Timer::T input_timer (this->input_timeout,
			    [this]() { this->input_timeout_signal.send (); });
			response = this->readResponse (&input_stream);
		}
		this->input_timeout_signal.recieve ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::Error::T ("Reading response timed out\n");
	}

	this->response_queue.pop ().set (response);
}
