void
T::readClose (const FrameHeader::T & frame_header,
    IO::Interface::InputStream::T & input_stream)
{
	Masking::InputStream::T masking_input_stream (
	    input_stream, frame_header.masking_key);

	close_message.emplace (masking_input_stream, frame_header.payload_length);

	this->output.cancel (close_message.value ());

	throw Failure::EndOfResource::T ();
}
