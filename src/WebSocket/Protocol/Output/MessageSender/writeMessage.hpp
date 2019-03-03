void
T::writeMessage (Message::T & message,
    IO::Interface::OutputStream::T & output_stream,
    IO::CancelSignal::T & output_timeout_signal)
{
	uint64_t remaining_bytes = (uint64_t) message.size ();

	uint64_t next_chunk_size =
	    remaining_bytes < this->chunk_size ? remaining_bytes : chunk_size;

	remaining_bytes -= next_chunk_size;

	FrameHeader::T message_header (!remaining_bytes,
	    false,
	    false,
	    false,
	    message.type (),
	    next_chunk_size,
	    {0});

	this->writeFrame (
	    message_header, message, output_stream, output_timeout_signal);

	while (remaining_bytes)
	{
		uint64_t next_chunk_size =
		    remaining_bytes < this->chunk_size ? remaining_bytes : chunk_size;

		remaining_bytes -= next_chunk_size;

		FrameHeader::T continuation_header (!remaining_bytes,
		    false,
		    false,
		    false,
		    Type::CONTINUATION,
		    next_chunk_size,
		    {0});

		this->writeFrame (
		    continuation_header, message, output_stream, output_timeout_signal);
	}
}
