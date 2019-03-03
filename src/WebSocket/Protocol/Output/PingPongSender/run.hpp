void
T::run (IO::Interface::OutputStream::T & output_stream,
    IO::CancelSignal::T & output_timeout_signal)
{
	Scope::T output_scope (std::move (this->output_scope));

	try
	{
		while (true)
		{
			auto [type, payload] = this->output_queue.pop ();

			FrameHeader::T frame_header (
			    true, false, false, false, type, payload.size (), {0});

			this->writeFrame (
			    frame_header, payload, output_stream, output_timeout_signal);
		}
	}
	catch (Failure::EndOfResource::T)
	{
	}
}
