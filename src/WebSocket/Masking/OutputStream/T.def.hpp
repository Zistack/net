template <typename OutputStream>
T <OutputStream>::T
(
	OutputStream output_stream,
	std::array <uint8_t, 4> masking_key
)
:	output_stream (output_stream),
	masking_key (masking_key),
	masking_key_index (0)
{
}
