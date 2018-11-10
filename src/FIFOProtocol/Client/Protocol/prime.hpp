template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::prime (
    IO::Interface::NonblockingInputStream::T & input_stream,
    IO::Interface::NonblockingOutputStream::T & output_stream)
{
	this->input_stream = std::make_unique<IO::Blocking::InputStream::T> (
	    input_stream, this->input_timeout_signal);
	this->output_stream = std::make_unique<IO::Blocking::OutputStream::T> (
	    output_stream, this->output_timeout_signal);

	this->nursery =
	    std::make_unique<Thread::Nursery::T> (this->exception_store);

	this->response_queue_scope = std::move (
	    Scope::T<decltype (this->response_queue)> (this->response_queue));
	this->shutdown_signal_scope =
	    std::move (SuppressingScope::T<decltype (this->shutdown_signal)> (
	        this->shutdown_signal, this->exception_store));
	this->status_bit_scope =
	    std::move (Scope::T<decltype (this->status_bit)> (this->status_bit));
}
