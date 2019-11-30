template <typename Interface>
template <typename InputStream>
void
T <Interface>::readPing
(
	const FrameHeader::T & frame_header,
	InputStream && input_stream
)
{
	std::vector <uint8_t> payload (frame_header . payload_length);

	Masking::InputStream::T masking_input_stream
	(
		std::forward <InputStream> (input_stream),
		frame_header . masking_key
	);

	uint64_t i;
	for (i = 0; i < frame_header . payload_length; ++ i)
	{
		payload . push_back ((uint8_t) masking_input_stream . get ());
	}

	this -> interface () . pongOutput (payload);
}
