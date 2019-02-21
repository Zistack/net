template <typename RequestType>
void
T<RequestType>::prime ()
{
	this->request_queue.open ();
}
