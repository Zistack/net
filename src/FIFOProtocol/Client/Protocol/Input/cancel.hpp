template <typename RequestType, typename ResponseType>
void
T<RequestType, ResponseType>::cancel ()
{
	this->response_queue.close ();
	this->response_queue.flush ();

	this->input_shutdown_signal.cancel ();
}
