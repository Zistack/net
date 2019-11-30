template <typename Interface>
template <typename InputStream>
void
T <Interface>::readClose
(
	const FrameHeader::T & frame_header,
	InputStream && input_stream
)
{
	Masking::InputStream::T masking_input_stream
	(
		std::forward <InputStream> (input_stream),
		frame_header . masking_key
	);

	this -> m_close_message . emplace
	(
		masking_input_stream,
		frame_header . payload_length
	);

	this -> interface () . cancelOutput (this -> m_close_message . value ());

	throw Failure::EndOfResource::T ();
}
