void
T::writeFrame (const FrameHeader::T & frame_header,
    const std::vector<uint8_t> & payload,
    IO::Interface::OutputStream::T & output_stream,
    IO::CancelSignal::T & output_timeout_signal)
{
	Masking::OutputStream::T masking_output_stream (
	    output_stream, frame_header.masking_key);

	std::unique_lock<Thread::SleepMutex::T> output_lock (this->output_mutex);

	try
	{
		{
			Thread::Timer::T (this->output_timeout,
			    &IO::CancelSignal::T::cancel,
			    output_timeout_signal);

			frame_header.writeTo (output_stream);

			masking_output_stream.write (
			    (const char *) payload.data (), payload.size ());
		}
		output_timeout_signal.clear ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Writing frame timed out\n");
	}
}
