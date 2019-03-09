template <typename Response, typename Interface>
void
T<Response, Interface>::prime ()
{
	this->response_scope =
	    Scope::T<decltype (this->response_queue)> (this->response_queue);
}
