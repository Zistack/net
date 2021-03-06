template <typename Interface>
template <typename OutputStream>
void
T <Interface>::writeMessage (Message::T & message, OutputStream && output_stream)
{
	uint64_t remaining_bytes = (uint64_t) message . size ();
	uint64_t position = 0;

	uint64_t next_chunk_size =
		remaining_bytes < this -> m_chunk_size ?
		remaining_bytes :
		this -> m_chunk_size;

	remaining_bytes -= next_chunk_size;

	Masking::Key::T masking_key;
	{
		std::unique_lock rng_lock (this -> interface () . rng_mutex);
		this ->
			interface () .
			rng .
			generate (masking_key . data (), masking_key . size ());
	}
	FrameHeader::T message_header
	(
		! remaining_bytes,
		false,
		false,
		false,
		message . type (),
		next_chunk_size,
		masking_key
	);

	this -> writeFrame
	(
		message_header,
		message,
		position,
		std::forward <OutputStream> (output_stream)
	);

	position += next_chunk_size;

	while (remaining_bytes)
	{
		uint64_t next_chunk_size =
			remaining_bytes < this -> m_chunk_size ?
			remaining_bytes :
			this -> m_chunk_size;

		remaining_bytes -= next_chunk_size;

		{
			std::unique_lock rng_lock (this -> interface () . rng_mutex);
			this ->
				interface () .
				rng .
				generate (masking_key . data (), masking_key . size ());
		}
		FrameHeader::T continuation_header
		(
			! remaining_bytes,
			false,
			false,
			false,
			Type::CONTINUATION,
			next_chunk_size,
			masking_key
		);

		this -> writeFrame
		(
			continuation_header,
			message,
			position,
			std::forward <OutputStream> (output_stream)
		);

		position += next_chunk_size;
	}
}
