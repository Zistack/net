template <typename Interface>
template <typename InputStream>
void
T <Interface>::readContinuation
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

	this -> m_message -> withWriterAt
	(
		Message::Writer::T
		(
			masking_input_stream,
			frame_header . payload_length,
			entity_slot
		),
		this -> m_message -> size ()
	);

	if (frame_header . final_frame) this -> finalizeMessage ();
}
