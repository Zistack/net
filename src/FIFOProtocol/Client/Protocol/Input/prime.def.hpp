template <typename Protocol, typename Response, typename Details>
void
T <Protocol, Response, Details>::prime ()
{
	this -> m_input_shutdown_scope = std::move
	(
		SuppressingScope::T
		(
			this -> m_input_shutdown_signal,
			this -> m_exception_store
		)
	);

	this -> m_response_scope = std::move (Scope::T (this -> m_response_queue));
}
