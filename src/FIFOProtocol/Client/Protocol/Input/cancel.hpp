template <typename ResponseType>
void
T<ResponseType>::cancel ()
{
	this->response_queue.close ();
	this->response_queue.flush ();

	this->input_shutdown_signal.cancel ();
}
