template <typename RequestType, typename ResponseType>
void
T<RequestType, ResponseType>::prime ()
{
	this->input_shutdown_scope = SuppressingScope::T<Shutdown::Signal::T> (
	    this->input_shutdown_signal, this->exception_store);
}
