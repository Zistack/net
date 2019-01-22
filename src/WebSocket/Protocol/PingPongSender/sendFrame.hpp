void
T::sendFrame (const FrameHeader::T & frame_header,
    IO::Interface::InputStream::T & input_stream,
    IO::Interface::OutputStream::T & output_stream,
    IO::CancelSignal::T & output_timeout_signal)
{
	std::unique_lock<Thread::SleepMutex::T> output_lock (this->output_mutex);

	{
		Thread::Timer::T (this->output_timeout,
		    &IO::CancelSignal::T::cancel,
		    output_timeout_signal);

		frame_header.writeTo (output_stream);

		Util::transfer (input_stream,
		    frame_header.payload_length,
		    frame_header.masking_key,
		    output_stream);
	}
	output_timeout_signal.clear ();
}
