template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::stop ()
{
	this->shutdown_signal.reset ();
	this->response_queue.cancel ();
}
