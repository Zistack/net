template <typename RequestType, typename ResponseType>
void
T<RequestType, ResponseType>::prime ()
{
	this->request_scope =
	    Scope::T<decltype (this->request_queue)> (this->request_queue);
}
