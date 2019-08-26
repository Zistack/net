template <typename Protocol, typename Dispatcher>
template <typename InputStream>
void
T <Protocol, Dispatcher>::readClose
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

	this -> output () . cancel (this -> m_close_message . value ());

	throw Failure::EndOfResource::T ();
}
