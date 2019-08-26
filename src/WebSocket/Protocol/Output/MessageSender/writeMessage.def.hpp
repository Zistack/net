template <typename Output>
template <typename OutputStream>
void
T <Output>::writeMessage (Message::T & message, OutputStream && output_stream)
{
	uint64_t remaining_bytes = (uint64_t) message . size ();
	uint64_t position = 0;

	uint64_t next_chunk_size =
		remaining_bytes < this -> m_chunk_size ?
		remaining_bytes :
		this -> m_chunk_size;

	remaining_bytes -= next_chunk_size;

	std::array <uint8_t, 4> masking_key;
	{
		std::unique_lock rng_lock (this -> rngMutex ());
		this -> rng () . generate (masking_key . data (), 4);
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
			std::unique_lock rng_lock (this -> rngMutex ());
			this -> rng () . generate (masking_key . data (), 4);
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
