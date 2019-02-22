template <typename RequestType, typename ResponseType>
void
T<RequestType, ResponseType>::prime ()
{
	this->request_queue.open ();
}
