template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::event ()
{
	ResponseType response;

	try
	{
		{
			Thread::Timeout::T (this->input_timeout,
			    [&]() { this->input_timeout_signal->send (); });
			response = this->readResponse (this->input_stream);
		}
		this->input_timeout_signal->recieve ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::Error::T ("Reading response timed out\n");
	}

	std::promise<ResponseType> * promise = response_queue.pop ();

	promise->set_value (response);
}
