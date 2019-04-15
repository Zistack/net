template <typename Dispatcher>
void
T <Dispatcher>::prime ()
{
	this -> input_shutdown_scope = SuppressingScope::T
	(
		this -> input_shutdown_signal,
		this -> exception_store
	);
}
