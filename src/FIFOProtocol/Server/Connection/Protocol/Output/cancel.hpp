template <typename RequestType, typename ResponseType>
void
T<RequestType, ResponseType>::cancel ()
{
	this->response_queue.close ();
	this->response_queue.flush ();
}
