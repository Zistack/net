template <typename RequestType, typename ResponseType>
void
T<RequestType, ResponseType>::prime ()
{
	this->response_queue.open ();

	this->input_shutdown_scope =
	    std::move (SuppressingScope::T<Shutdown::Signal::T> (
	        this->input_shutdown_signal, this->exception_store));
}
