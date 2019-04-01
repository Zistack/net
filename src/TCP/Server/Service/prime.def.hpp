template <typename ServerProtocol>
void
T <ServerProtocol>::prime ()
{
	this -> shutdown_scope = SuppressingScope::T
	(
		this->shutdown_signal,
		this->exception_store
	);
}
