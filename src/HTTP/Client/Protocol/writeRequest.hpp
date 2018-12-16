void
T::writeRequest (const Request::T & request,
    IO::Blocking::OutputStream::T & output_stream,
    IO::CancelSignal::T & output_cancel_signal,
    Failure::CancelScope::T & output_cancel_scope)
{
	// That nullptr should be configurable.
	request.writeTo (
	    nullptr, output_stream, output_cancel_signal, output_cancel_scope);
}
