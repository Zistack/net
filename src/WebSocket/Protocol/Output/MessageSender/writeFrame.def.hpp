template <typename OutputStream>
void
T::writeFrame
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

	std::unique_lock output_lock (this -> output_mutex);

	try
	{
		{
			Thread::Timer::T output_timeout
			(
				this -> output_timeout,
				& decltype (cancel_handle)::cancel,
				& cancel_handle
			);

			if constexpr (IO::TypeTraits::IsBuffered::T <OutputStream>::value)
			{
				Scope::T output_scope (output_stream);

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
			}
			else
			{
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
			}
		}
		if constexpr (IO::TypeTraits::IsClearable::T <OutputStream>::value)
		{
			output_stream . clear ();
		}
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Writing frame timed out\n");
	}
}

