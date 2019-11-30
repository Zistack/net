template <typename OutputStream>
void
T::close (OutputStream && output_stream)
{
	Masking::Key::T masking_key;
	this -> rng . generate (masking_key . data (), masking_key . size ());
	FrameHeader::T close_header
	(
		true,
		false,
		false,
		false,
		Type::CLOSE,
		this -> m_close_message . length (),
		masking_key
	);

	Masking::OutputStream::T masking_output_stream
	(
		std::forward <OutputStream> (output_stream),
		masking_key
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

				this -> m_close_message . writeTo (masking_output_stream);
			}
			else
			{
				close_header . writeTo
				(
					std::forward <OutputStream> (output_stream)
				);

				this -> m_close_message . writeTo (masking_output_stream);
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
