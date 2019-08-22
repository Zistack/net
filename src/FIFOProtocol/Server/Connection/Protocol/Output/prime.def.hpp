template <typename Protocol, typename Response, typename Details>
void
T <Protocol, Response, Details>::prime ()
{
	this -> m_response_scope = std::move (Scope::T (this -> m_response_queue));
}
