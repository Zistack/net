template <typename ResponseType>
void
T<ResponseType>::run (
    IO::Interface::NonblockingInputStream::T & nonblocking_input_stream)
{
	SuppressingScope::T<Shutdown::Signal::T> input_shutdown_scope (
	    std::move (this->input_shutdown_scope));

	IO::CancelSignal::T input_cancel_signal;
	IO::Blocking::InputStream::T input_stream (
	    nonblocking_input_stream, input_cancel_signal);

	::Protocol::eventLoop (this->exception_store,
	    input_stream,
	    this->input_shutdown_signal,
	    &T::event,
	    this,
	    input_stream,
	    input_cancel_signal);

	exception_store.pop ();
}
