template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::prime (
    IO::Interface::NonblockingInputStream::T & input_stream,
    IO::Interface::NonblockingOutputStream::T & output_stream)
{
	this->input_stream = std::make_unique<IO::Blocking::InputStream::T> (
	    input_stream, this->input_cancel_signal);
	this->output_stream = std::make_unique<IO::Blocking::OutputStream::T> (
	    output_stream, this->output_cancel_signal);

	this->response_queue_scope =
	    Scope::T<decltype (this->response_queue)> (this->response_queue);
	this->shutdown_signal_scope =
	    SuppressingScope::T<decltype (this->shutdown_signal)> (
	        this->shutdown_signal, this->exception_store);
}
