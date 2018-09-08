template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::clean ()
{
	this->lock ();
	this->active = false;
	this->unlock ();

	this->response_queue.close ();
	this->cleanQueue ();

	delete this->input_timeout_signal;
	delete this->input_stream;

	delete this->output_timeout_signal;
	delete this->output_stream;
}
