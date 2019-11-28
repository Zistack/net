template <typename Interface, typename Request>
void
T <Interface, Request>::prime ()
{
	this -> m_request_scope = std::move (Scope::T (this -> m_request_queue));
}
