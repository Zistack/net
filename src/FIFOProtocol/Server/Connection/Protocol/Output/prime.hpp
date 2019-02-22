template <typename RequestType, typename ResponseType>
void
T<RequestType, ResponseType>::prime ()
{
	this->response_queue.open ();
}
