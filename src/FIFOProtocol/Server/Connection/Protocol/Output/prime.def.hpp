template <typename Interface, typename Response>
void
T <Interface, Response>::prime ()
{
	this -> m_response_scope = std::move (Scope::T (this -> m_response_queue));
}
