void
T::run (IO::Interface::OutputStream::T & output_stream,
    IO::CancelSignal::T & output_timeout_signal)
{
	try
	{
		while (true)
		{
			auto [type, payload] = this->output_queue.pop ();

			FrameHeader::T pong_header (
			    true, false, false, false, type, payload.size (), {0});

			decltype (payload)::size_type pointer;
			IO::Vector::PeekableInputStream::T input_stream (payload, pointer);

			this->sendFrame (pong_header,
			    input_stream,
			    output_stream,
			    output_timeout_signal);
		}
	}
	catch (Failure::EndOfResource::T)
	{
	}
}
