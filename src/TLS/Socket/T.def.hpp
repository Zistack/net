T::T () : m_tcp_socket (-1)
{
}

T::T (int tcp_socket, struct tls * tls_context)
:	m_tcp_socket (tcp_socket), m_tls_context (tls_context)
{
}

T::T (T && other)
:	m_tcp_socket (other . m_tcp_socket),
	m_tls_context (std::move (other . m_tls_context))
{
	other . m_tcp_socket = -1;
}
