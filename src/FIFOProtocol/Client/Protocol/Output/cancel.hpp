template <typename RequestType>
void
T<RequestType>::cancel ()
{
	this->request_queue.close ();
	this->request_queue.flush ();
}
