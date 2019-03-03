void
T::readPing (const FrameHeader::T & frame_header,
    IO::Interface::InputStream::T & input_stream)
{
	std::vector<uint8_t> payload (frame_header.payload_length);

	Masking::InputStream::T masking_input_stream (
	    input_stream, frame_header.masking_key);

	uint64_t i;
	for (i = 0; i < frame_header.payload_length; ++i)
	{
		payload.push_back ((uint8_t) input_stream.get ());
	}

	this->output.pong (payload);
}
