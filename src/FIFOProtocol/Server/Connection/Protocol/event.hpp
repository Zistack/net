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
			Failure::CancelScope::T input_cancel_scope;
			Thread::Timer::T input_timer (this->config.input_timeout,
			    [&input_cancel_scope]() { input_cancel_scope.cancel (); });
			request = std::move (this->readRequest (
			    input_stream, this->input_cancel_signal, input_cancel_scope));
		}
		this->input_cancel_signal.clear ();
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

	nursery.add ([this, request (std::move (request)), response_delay]() {
		this->computeResponse (request, response_delay);
	});
}
