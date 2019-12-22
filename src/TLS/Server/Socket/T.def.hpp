T::T () : m_tcp_socket (-1)
{
}

T::T (const TCP::Config::T & tcp_config)
:	m_tcp_socket
	(
		TCP::Util::server (tcp_config . hostname (), tcp_config . port ())
	)
{
}

T::T (T && other)
:	m_tcp_socket (other . m_tcp_socket)
{
	other . m_tcp_socket = -1;
}
