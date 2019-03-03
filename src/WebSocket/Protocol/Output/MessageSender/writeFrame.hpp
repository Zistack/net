void
T::writeFrame (const FrameHeader::T & frame_header,
    Message::T & message,
    IO::Interface::OutputStream::T & output_stream,
    IO::CancelSignal::T & output_timeout_signal)
{
	Masking::OutputStream::T masking_output_stream (
	    output_stream, frame_header.masking_key);

	std::unique_lock<Thread::SleepMutex::T> output_lock (this->output_mutex);

	try
	{
		{
			Thread::Timer::T output_timeout (this->output_timeout,
			    &IO::CancelSignal::T::cancel,
			    output_timeout_signal);

			frame_header.writeTo (output_stream);

			message.write (frame_header.payload_length,
			    masking_output_stream,
			    output_timeout_signal);
		}
		output_timeout_signal.clear ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Writing frame timed out\n");
	}
}
