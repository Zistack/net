template <typename NonblockingInputStream>
T <NonblockingInputStream>::T (NonblockingInputStream input_stream)
:	m_input_stream (input_stream),
	m_begin (0),
	m_end (0),
	m_buffer (new char [T::BUFFER_SIZE]),
	m_eof_bit (false)
{
}
