void
T::clean ()
{
	if (this -> m_tcp_socket != -1) close (this -> m_tcp_socket);
}
