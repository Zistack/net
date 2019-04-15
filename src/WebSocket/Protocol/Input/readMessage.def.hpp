template <typename Dispatcher>
template <typename InputStream>
void
T <Dispatcher>::readMessage
(
	const FrameHeader::T & frame_header,
	InputStream && input_stream,
	InputEntitySlot::T & entity_slot
)
{
	Masking::InputStream::T masking_input_stream
	(
		std::forward <InputStream> (input_stream),
		frame_header . masking_key
	);

	this -> message . emplace
	(
		frame_header . opcode,
		frame_header . payload_length,
		this -> temp_file_threshhold
	);

	this -> message -> withWriter
	(
		Message::Writer::T
		(
			masking_input_stream,
			frame_header . payload_length,
			entity_slot
		)
	);

	if (frame_header . final_frame) this -> finalizeMessage ();
}
