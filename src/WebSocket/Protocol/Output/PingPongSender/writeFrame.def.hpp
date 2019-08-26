template <typename Output>
template <typename OutputStream>
void
T <Output>::writeFrame
(
	const FrameHeader::T & frame_header,
	const std::vector <uint8_t> & payload,
	OutputStream && output_stream
)
{
	Masking::OutputStream::T masking_output_stream
	(
		std::forward <OutputStream> (output_stream),
		frame_header . masking_key
	);

	std::unique_lock output_lock (this -> outputMutex ());

	try
	{
		{
			Thread::Timer::T
			(
				this -> outputTimeout (),
				& OutputStream::cancel,
				& output_stream
			);

			if constexpr (IO::TypeTraits::IsBuffered::T <OutputStream>::value)
			{
				Scope::T output_scope (output_stream);

				frame_header . writeTo
				(
					std::forward <OutputStream> (output_stream)
				);

				masking_output_stream . write
				(
					(const char *) payload . data (),
					payload . size ()
				);
			}
			else
			{
				frame_header . writeTo
				(
					std::forward <OutputStream> (output_stream)
				);

				masking_output_stream . write
				(
					(const char *) payload . data (),
					payload . size ()
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
