Reciever::T
T::reciever ()
{
	return
	{
		this -> m_tcp_socket,
		this -> m_tls_context . get (),
		this -> m_socket_mutex,
		this -> m_spurious_read
	};
}
