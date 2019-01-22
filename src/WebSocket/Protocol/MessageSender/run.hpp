void
T::run (IO::Interface::OutputStream::T & output_stream,
    IO::CancelSignal::T & output_timeout_signal)
{
	try
	{
		while (true)
		{
			std::unique_ptr<Message::T> message =
			    std::move (this->output_queue.pop ());

			uint64_t remaining_bytes = (uint64_t) message->size ();

			uint64_t next_chunk_size = remaining_bytes < this->chunk_size ?
			    remaining_bytes :
			    chunk_size;

			remaining_bytes -= next_chunk_size;

			FrameHeader::T first_header (!remaining_bytes,
			    false,
			    false,
			    false,
			    message->type (),
			    next_chunk_size,
			    {0});

			this->sendFrame (
			    first_header, *message, output_stream, output_timeout_signal);

			while (remaining_bytes)
			{
				next_chunk_size = remaining_bytes < this->chunk_size ?
				    remaining_bytes :
				    this->chunk_size;

				remaining_bytes -= next_chunk_size;

				FrameHeader::T next_header (!remaining_bytes,
				    false,
				    false,
				    false,
				    Type::CONTINUATION,
				    next_chunk_size,
				    {0});

				this->sendFrame (next_header,
				    *message,
				    output_stream,
				    output_timeout_signal);
			}
		}
	}
	catch (Failure::EndOfResource::T)
	{
	}
}
