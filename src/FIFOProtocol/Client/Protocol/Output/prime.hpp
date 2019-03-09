template <typename Request, typename Interface>
void
T<Request, Interface>::prime ()
{
	this->request_scope =
	    Scope::T<decltype (this->request_queue)> (this->request_queue);
}
