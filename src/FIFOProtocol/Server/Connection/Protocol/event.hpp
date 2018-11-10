template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::event (
    IO::Blocking::InputStream::T & input_stream,
    Thread::Nursery::T & nursery)
{
	RequestType request;

	try
	{
		{
			Thread::Timer::T input_timer (this->input_timeout,
			    [&]() { this->input_timeout_signal.send (); });
			request = this->readRequest (input_stream);
		}
		this->input_timeout_signal.recieve ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::Error::T ("Reading request timed out\n");
	}

	::Protocol::Delay::T<ResponseType> response_delay;

	try
	{
		this->response_queue.push (response_delay);
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::Error::T ("Response queue is inactive\n");
	}

	nursery.add ([this, request, response_delay]() {
		this->computeResponse (request, response_delay);
	});
}
