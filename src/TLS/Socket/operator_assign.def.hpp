T &
T::operator = (T && other)
{
	this -> m_tcp_socket = other . m_tcp_socket;
	this -> m_tls_context = std::move (other . m_tls_context);

	other . m_tcp_socket = -1;

	return * this;
}
