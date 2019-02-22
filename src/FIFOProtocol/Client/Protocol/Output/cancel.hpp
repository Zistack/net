template <typename RequestType, typename ResponseType>
void
T<RequestType, ResponseType>::cancel ()
{
	this->request_queue.close ();
	this->request_queue.flush ();
}
