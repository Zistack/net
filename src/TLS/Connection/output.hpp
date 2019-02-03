void
T::output (IO::Interface::NonblockingInputStream::T & nonblocking_input_stream,
    ConnectionSocket::T & socket)
{
	IO::CancelSignal::T output_timeout_signal;
	IO::Blocking::InputStream::T & input_stream (
	    nonblocking_input_stream, output_timeout_signal);

	char output_buffer[this->buffer_size];

	Failure::ExceptionStore::T exception_store;

	::Protocol::eventLoop (exception_store,
	    nonblocking_input_stream,
	    this->output_shutdown_signal,
	    &T::outputEvent,
	    this,
	    input_stream,
	    output_buffer,
	    socket,
	    output_timeout_signal);

	exception_store.poll ();
}
