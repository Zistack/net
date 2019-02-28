void
T::processEvent (IO::Blocking::InputStream::T & input_stream,
    IO::CancelSignal::T & input_timeout_signal)
{
	try
	{
		{
			Thread::Timer::T input_timer (this->input_timeout,
			    &IO::CancelSignal::T::cancel,
			    &input_timeout_signal);

			FrameHeader::T frame_header (input_stream);

			try
			{
				frame_header . validate (this -> message);
			}
			catch (const Failure::SemanticError::T & e)
			{
				this -> exception_store . store (std::current_exception ());

				this -> cancel ();
				output -> cancel (CloseMessage::T (1002, e.what ()));

				Util::discard (input_stream, frame_header . payload_length);

				return;
			}

			if (frame_header.opcode == Type::PING)
			{
				this -> ping (frame_header, input_stream);
			}
			else if (frame_header.opcode == Type::PONG)
			{
				this -> pong (frame_header, input_stream);
			}
			else if (frame_header.isMessage ())
			{
				this -> message (frame_header, input_stream, input_timeout_signal);
			}
			else if (frame_header.opcode == Type::CONTINUATION)
			{
				this -> continuation (frame_header, input_stream, input_timeout_signal);
			}
			else if (frame_header.opcode == Type::CLOSE)
			{
				this -> close (frame_header, input_stream);
			}
		}
		input_timeout_signal.clear ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Reading frame timed out\n");
	}
}
