T::T () : m_tcp_socket (-1)
{
}

T::T
(
	const std::optional <URI::Authority::Host::T> & hostname,
	const std::optional <uint64_t> & port
)
:	m_tcp_socket (TCP::Util::server (hostname, port))
{
}

T::T (T && other)
:	m_tcp_socket (other . m_tcp_socket)
{
	other . m_tcp_socket = -1;
}
