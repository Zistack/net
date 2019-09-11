template <typename OutputStream>
T <OutputStream>::T
(
	OutputStream output_stream,
	Key::T masking_key
)
:	m_output_stream (output_stream),
	m_masking_key (masking_key),
	m_masking_key_index (0)
{
}
