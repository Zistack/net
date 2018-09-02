template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::event ()
{
	const std::string message_prefix =
	    "IO::FIFOProtocol::Server::Protocol::T::event\n";

	RequestType request;

	try
	{
		this->exception_store.poll ();

		{
			Thread::Timeout::T (this->input_timeout,
			    [&]() { this->input_timeout_signal->send (); });
			request = this->readRequest (this->input_stream);
		}
		this->input_timeout_signal->recieve ();
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}

	std::promise<ResponseType> * promise = new std::promise<ResponseType>;

	this->response_queue.push (promise);

	this->nursery.add (&T::computeResponse, this, request, promise);
}
