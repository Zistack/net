template <typename Request, typename Response, typename Interface>
void
T<Request, Response, Interface>::prime ()
{
	this->input_shutdown_scope = SuppressingScope::T<Shutdown::Signal::T> (
	    this->input_shutdown_signal, this->exception_store);
}
