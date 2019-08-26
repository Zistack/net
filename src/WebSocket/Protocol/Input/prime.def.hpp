template <typename Protocol, typename Dispatcher>
void
T <Protocol, Dispatcher>::prime ()
{
	this -> m_input_shutdown_scope = SuppressingScope::T
	(
		this -> m_input_shutdown_signal,
		this -> m_exception_store
	);
}
