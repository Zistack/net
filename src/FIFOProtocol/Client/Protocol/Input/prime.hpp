template <typename RequestType, typename ResponseType>
void
T<RequestType, ResponseType>::prime ()
{
	this->input_shutdown_scope =
	    std::move (SuppressingScope::T<Shutdown::Signal::T> (
	        this->input_shutdown_signal, this->exception_store));

	this->response_scope =
	    Scope::T<decltype (this->response_queue)> (this->response_queue);
}
