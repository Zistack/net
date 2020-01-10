template <typename Interface, typename Request, typename Response>
void
T <Interface, Request, Response>::prime ()
{
	this -> m_request_scope = std::move (Scope::T (this -> m_request_queue));
}
