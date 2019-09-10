template <typename OutputStream>
T <OutputStream>::T
(
	OutputStream output_stream,
	Key::T masking_key
)
:	output_stream (output_stream),
	masking_key (masking_key),
	masking_key_index (0)
{
}
