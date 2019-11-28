template <typename Interface, typename Request, typename Response>
void
T <Interface, Request, Response>::prime ()
{
	this -> m_input_shutdown_scope = SuppressingScope::T
	(
		this -> m_input_shutdown_signal,
		this -> m_exception_store
	);
}
