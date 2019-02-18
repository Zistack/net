void
T::input (ConnectionSocket::T & socket,
    IO::Interface::NonblockingOutputStream::T & nonblocking_output_stream)
{
	IO::CancelSignal::T input_timeout_signal;
	IO::Blocking::OutputStream::T output_stream (
	    nonblocking_output_stream, input_timeout_signal);

	char input_buffer[this->buffer_size];

	Failure::ExceptionStore::T exception_store;

	::Protocol::eventLoop (exception_store,
	    socket.input_stream,
	    this->input_shutdown_signal,
	    &T::inputEvent,
	    this,
	    socket,
	    (char *) input_buffer,
	    output_stream,
	    input_timeout_signal);

	exception_store.poll ();
}
