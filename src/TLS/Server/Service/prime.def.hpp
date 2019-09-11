template <typename ServerProtocol>
void
T <ServerProtocol>::prime ()
{
	this -> m_shutdown_scope = SuppressingScope::T
	(
		this -> m_shutdown_signal,
		this -> m_exception_store
	);
}
