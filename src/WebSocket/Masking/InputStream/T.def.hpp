template <typename InputStream>
T <InputStream>::T
(
	InputStream input_stream,
	Key::T masking_key
)
:	input_stream (input_stream), masking_key (masking_key), masking_key_idx (0)
{
}
