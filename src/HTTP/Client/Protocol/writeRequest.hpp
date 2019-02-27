void
T::writeRequest (const Request::T & request,
    IO::Blocking::OutputStream::T & output_stream,
    IO::CancelSignal::T & output_cancel_signal,
    Failure::CancelScope::T & output_cancel_scope)
{
	request.writeTo (output_stream,
	    output_cancel_signal,
	    output_cancel_scope,
	    this->transfer_encoding_config);
}
