template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::event (
    IO::Blocking::InputStream::T & input_stream,
    IO::Signal::T & input_timeout_signal,
    Thread::Nursery::T & nursery)
{
	RequestType request;

	try
	{
		{
			Thread::Timer::T input_timer (
			    this->input_timeout, [&]() { input_timeout_signal.send (); });
			request = this->readRequest (&input_stream);
		}
		input_timeout_signal.recieve ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::Error::T ("Reading request timed out\n");
	}

	::Protocol::Delay::T<ResponseType> delay;

	try
	{
		delay = this->response_queue.push ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::Error::T ("Response queue is inactive\n");
	}

	nursery.add (
	    [this, request, delay]() { this->computeResponse (request, delay); });
}
