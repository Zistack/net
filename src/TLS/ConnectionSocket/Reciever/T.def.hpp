T::T
(
	int tcp_socket,
	struct tls * tls_context,
	std::mutex & socket_mutex,
	bool & spurious_read
)
:	m_tcp_socket (tcp_socket),
	m_tls_context (tls_context),
	m_socket_mutex (socket_mutex),
	m_spurious_read (spurious_read),
	m_begin (0),
	m_end (0),
	m_buffer (new char [BUFFER_SIZE]),
	m_eof_bit (false)
{
}
