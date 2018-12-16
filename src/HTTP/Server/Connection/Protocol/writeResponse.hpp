void
T::writeResponse (const Response::T & response,
    IO::Blocking::OutputStream::T & output_stream,
    IO::CancelSignal::T & output_cancel_signal,
    Failure::CancelScope::T & output_cancel_scope)
{
	// That nullptr should be configurable.
	response.writeTo (
	    nullptr, output_stream, output_cancel_signal, output_cancel_scope);
}
