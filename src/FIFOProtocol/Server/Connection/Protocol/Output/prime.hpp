template <typename RequestType, typename ResponseType>
void
T<RequestType, ResponseType>::prime ()
{
	this->response_scope =
	    Scope::T<decltype (this->response_queue)> (this->response_queue);
}
