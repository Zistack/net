template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::clean ()
{
	this->response_queue.close ();
	this->nursery.join ();
	this->cleanQueue ();

	delete this->input_timeout_signal;
	delete this->input_stream;

	delete this->output_timeout_signal;
	delete this->output_stream;
}
