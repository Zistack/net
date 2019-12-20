template <typename Interface>
T <Interface>::T ()
:	m_input_buffer_size
	(
		gnutls_record_get_max_size (this -> interface () . session) -
		gnutls_record_overhead_size (this -> interface () . session)
	),
	m_begin (0),
	m_end (0),
	m_buffer (new char [this -> m_input_buffer_size]),
	m_eof_bit (false)
{
}
