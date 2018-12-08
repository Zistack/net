void
T::encode (Entity::T & entity,
    IO::Interface::OutputStream::T & output_stream,
    IO::CancelSignal::T & output_cancel_signal,
    Failure::CancelScope::T & cancel_scope)
{
	if (entity.isBlocking ())
	{
		this->filter (entity.asBlocking ().inputStream (),
		    nullptr,
		    output_stream,
		    &output_cancel_signal,
		    cancel_scope);
	}
	else if (entity.isNonblocking ())
	{
		IO::CancelSignal::T input_cancel_signal;
		IO::Blocking::InputStream::T input_stream (
		    entity.asNonblocking ().inputStream (), input_cancel_signal);

		this->filter (input_stream,
		    &input_cancel_signal,
		    output_stream,
		    &output_cancel_signal,
		    cancel_scope);
	}
}
