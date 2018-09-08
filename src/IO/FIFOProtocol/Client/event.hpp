template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::event ()
{
	ResponseType response;

	{
		Thread::Timeout::T (this->input_timeout,
		    [&]() { this->input_timeout_signal->send (); });
		response = this->readResponse (this->input_stream);
	}
	this->input_timeout_signal->recieve ();

	std::promise<ResponseType> * promise = response_queue.pop ();

	promise->set_value (response);
}
