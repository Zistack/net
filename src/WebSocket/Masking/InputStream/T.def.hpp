template <typename InputStream>
T <InputStream>::T
(
	InputStream input_stream,
	Key::T masking_key
)
:	m_input_stream (input_stream),
	m_masking_key (masking_key),
	m_masking_key_index (0)
{
}
