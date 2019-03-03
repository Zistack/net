void
T::waitEvent (IO::Interface::InputStream::T & input_stream,
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
				frame_header.validate ((bool) this->message);
			}
			catch (Failure::SemanticError::T)
			{
				this->exception_store.store (std::current_exception ());

				Util::discard (input_stream, frame_header.payload_length);

				return;
			}

			if (frame_header.opcode == Type::CLOSE)
			{
				this->readClose (frame_header, input_stream);
			}
			else
			{
				Util::discard (input_stream, frame_header.payload_length);
			}
		}
		input_timeout_signal.clear ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Reading frame timed out\n");
	}
}
