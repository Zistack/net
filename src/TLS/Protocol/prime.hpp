void
T::prime (IO::Interface::NonblockingInputStream::T & input_stream,
    IO::Interface::NonblockingOutputStream::T & output_stream)
{
	this->input_stream = &input_stream;
	this->output_stream = &output_stream;

	this->context = this->newContext (input_stream, output_stream);

	this->socket_to_protocol = std::make_unique<IO::Pipe::T> ();
	this->protocol_to_socket = std::make_unique<IO::Pipe::T> ();

	this->output_stream_to_protocol =
	    std::make_unique<IO::Blocking::OutputStream::T> (
	        socket_to_protocol->outputStream (), this->input_timeout_signal);

	this->input_shutdown_signal_scope =
	    SuppressingScope::T<decltype (this->input_shutdown_signal)> (
	        this->input_shutdown_signal, this->exception_store);
	this->output_shutdown_signal_scope =
	    SuppressingScope::T<decltype (this->output_shutdown_signal)> (
	        this->output_shutdown_signal, this->exception_store);

	this->protocol.prime (this->socket_to_protocol->inputStream (),
	    this->protocol_to_socket->outputStream ());
}
