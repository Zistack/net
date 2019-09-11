template <typename NonblockingOutputStream>
T <NonblockingOutputStream>::T (NonblockingOutputStream output_stream)
:	m_output_stream (output_stream),
	m_next (0),
	m_buffer (new char [T::BUFFER_SIZE])
{
}
