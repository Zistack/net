Response::T
T::readResponse (IO::Blocking::InputStream::T & input_stream,
    IO::CancelSignal::T & input_cancel_signal,
    Failure::CancelScope::T & input_cancel_scope)
{
	return Response::T (input_stream, input_cancel_signal, input_cancel_scope);
}
