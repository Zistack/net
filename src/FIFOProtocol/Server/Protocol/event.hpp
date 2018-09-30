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
			    [this]() { this->input_timeout_signal.send (); });
			request = this->readRequest (&input_stream);
		}
		this->input_timeout_signal.recieve ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::Error::T ("Reading request timed out\n");
	}

	std::promise<ResponseType> * promise = new std::promise<ResponseType>;

	this->response_queue.push (promise);

	nursery.add ([this, request, promise]() {
		this->computeResponse (request, promise);
	});
}
