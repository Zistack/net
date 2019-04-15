template <typename OutputStream>
void
T::close (OutputStream && output_stream)
{
	FrameHeader::T close_header
	(
		true,
		false,
		false,
		false,
		Type::CLOSE,
		this -> close_message . length (),
		{0}
	);

	Masking::OutputStream::T masking_output_stream
	(
		std::forward <OutputStream> (output_stream),
		close_header . masking_key
	);

	try
	{
		{
			Thread::Timer::T output_timer
			(
				this -> output_timeout,
				& OutputStream::cancel,
				& output_stream
			);

			if constexpr (IO::TypeTraits::IsBuffered::T <OutputStream>::value)
			{
				Scope::T output_scope (output_stream);

				close_header . writeTo
				(
					std::forward <OutputStream> (output_stream)
				);

				this -> close_message . writeTo (masking_output_stream);
			}
			else
			{
				close_header . writeTo
				(
					std::forward <OutputStream> (output_stream)
				);

				this -> close_message . writeTo (masking_output_stream);
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
