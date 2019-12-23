template <typename Interface>
template <typename InputStream>
void
T <Interface>::waitEvent (InputStream && input_stream)
{
	try
	{
		{
			Thread::Timer::T input_timer
			(
				this -> m_input_timeout,
				[&] () { input_stream . cancel (); }
			);

			FrameHeader::T frame_header (input_stream);

			try
			{
				frame_header . validate ((bool) this -> m_message);
			}
			catch (Failure::SemanticError::T)
			{
				this -> m_exception_store . store (std::current_exception ());

				Util::discard
				(
					std::forward <InputStream> (input_stream),
					frame_header . payload_length
				);

				return;
			}

			if (frame_header . opcode == Type::CLOSE)
			{
				this -> readClose
				(
					frame_header,
					std::forward <InputStream> (input_stream)
				);
			}
			else
			{
				Util::discard
				(
					std::forward <InputStream> (input_stream),
					frame_header . payload_length
				);
			}
		}
		if constexpr (IO::IsClearable::T <InputStream>::value)
		{
			input_stream . clear ();
		}
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Reading frame timed out\n");
	}
}
