template <typename Interface>
template <typename OutputStream>
void
T <Interface>::writeFrame
(
	const FrameHeader::T & frame_header,
	Message::T & message,
	uint64_t chunk_position,
	OutputStream && output_stream
)
{
	Masking::OutputStream::T masking_output_stream
	(
		std::forward <OutputStream> (output_stream),
		frame_header . masking_key
	);

	OutputEntitySlot::T entity_slot;
	Failure::CancellableAggregate::T cancel_handle (entity_slot, output_stream);

	std::unique_lock output_lock (this -> interface () . output_mutex);

	try
	{
		{
			Thread::Timer::T output_timeout
			(
				this -> interface () . output_timeout,
				[&] () { cancel_handle . cancel (); }
			);

			frame_header . writeTo
			(
				std::forward <OutputStream> (output_stream)
			);

			message . withReaderAt
			(
				Message::Reader::T
				(
					frame_header . payload_length,
					masking_output_stream,
					entity_slot
				),
				chunk_position
			);

			if constexpr (IO::IsBuffered::T <OutputStream>::value)
			{
				output_stream . flush ();
			}
		}
		if constexpr (IO::IsClearable::T <OutputStream>::value)
		{
			output_stream . clear ();
		}
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Writing frame timed out\n");
	}
}
