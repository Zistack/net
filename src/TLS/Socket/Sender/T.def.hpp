template <typename Interface>
T <Interface>::T (size_t config_max_record_size)
:	m_output_buffer_size (this -> outputBufferSize (config_max_record_size)),
	m_next (0),
	m_buffer (new char [this -> m_output_buffer_size])
{
}
