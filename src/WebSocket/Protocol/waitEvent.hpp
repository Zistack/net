void
T::waitEvent (IO::Blocking::InputStream::T & input_stream,
    IO::CancelSignal::T & input_timeout_signal)
{
	try
	{
		{
			Thread::Timer::T input_timer (this->input_timeout,
			    &IO::CancelSignal::T::cancel,
			    input_timeout_signal);

			FrameHeader::T frame_header (input_stream);

			if (frame_header.opcode == Type::CLOSE)
			{
				if (frame_header.payload_length > 125)
				{
					throw Failure::SemanticError::T (
					    "Control frames may not have a payload of more than "
					    "125 bytes\n");
				}

				if (!frame_header.final_frame)
				{
					throw Failure::SemanticError::T (
					    "Control frames may not have fragmented payloads\n");
				}

				this->loadCloseBuffer (frame_header, input_stream);

				throw Failure::EndOfResource::T ();
			}
			else
			{
				// IDK if I wanna do any real validation or not.

				size_t i;
				for (i = 0; i < frame_header.payload_length; ++i)
					input_stream.get ();
			}
		}
		input_timeout_signal.clear ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Reading frame timed out\n");
	}
}
