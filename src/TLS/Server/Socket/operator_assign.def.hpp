T &
T::operator = (T && other)
{
	this -> clean ();

	this -> m_tcp_socket = other . m_tcp_socket;

	other . m_tcp_socket = -1;

	return * this;
}
