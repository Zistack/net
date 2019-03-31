template <typename Response, typename Interface>
void
T <Response, Interface>::prime ()
{
	this -> input_shutdown_scope = std::move
	(
		SuppressingScope::T (this->input_shutdown_signal, this->exception_store)
	);

	this -> response_scope = std::move (Scope::T (this -> response_queue));
}
