template <typename Response, typename Interface>
void
T <Response, Interface>::prime ()
{
	this -> response_scope = std::move (Scope::T (this->response_queue));
}
