template <typename Request, typename Interface>
void
T <Request, Interface>::prime ()
{
	this -> request_scope = std::move (Scope::T (this -> request_queue));
}
