void
T::readMessage (const FrameHeader::T & frame_header,
    IO::Interface::InputStream::T & input_stream,
    IO::CancelSignal::T & input_timeout_signal)
{
	Masking::InputStream::T masking_input_stream (
	    input_stream, frame_header.masking_key);

	this->message = std::make_unique<Message::T> (frame_header.opcode,
	    this->pickEntity (
	        frame_header.final_frame, frame_header.payload_length));

	this->message->append (masking_input_stream,
	    frame_header.payload_length,
	    input_timeout_signal);

	if (frame_header.final_frame) this->finalizeMessage (frame_header);
}
