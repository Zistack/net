void
T::decode (IO::Interface::InputStream::T & input_stream,
    IO::CancelSignal::T & input_cancel_signal,
    Entity::T & entity,
    Failure::CancelScope::T & cancel_scope)
{
	if (entity.isBlocking ())
	{
		this->recode (input_stream,
		    &input_cancel_signal,
		    entity.asBlocking ().outputStream (),
		    nullptr,
		    cancel_scope);
	}
	else if (entity.isNonblocking ())
	{
		IO::CancelSignal::T output_cancel_signal;
		IO::Blocking::OutputStream::T output_stream (
		    entity.asNonblocking ().outputStream (), output_cancel_signal);

		this->recode (input_stream,
		    &input_cancel_signal,
		    output_stream,
		    &output_cancel_signal,
		    cancel_scope);
	}
}
