void
T::close (IO::Interface::OutputStream::T & output_stream,
    IO::CancelSignal::T & output_cancel_signal)
{
	FrameHeader::T close_header (true,
	    false,
	    false,
	    false,
	    Type::CLOSE,
	    this->close_message.length (),
	    {0});

	Masking::OutputStream::T masking_output_stream (
	    output_stream, close_header.masking_key);

	try
	{
		{
			Thread::Timer::T output_timer (this->output_timeout,
			    &IO::CancelSignal::T::cancel,
			    &output_cancel_signal);

			close_header.writeTo (output_stream);
			this->close_message.writeTo (masking_output_stream);
		}
		output_cancel_signal.clear ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Writing frame timed out\n");
	}
}
