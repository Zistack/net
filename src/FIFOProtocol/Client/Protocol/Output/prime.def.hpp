template <typename Protocol, typename Request, typename Details>
void
T <Protocol, Request, Details>::prime ()
{
	this -> m_request_scope = std::move (Scope::T (this -> m_request_queue));
}
