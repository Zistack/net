Sender::T
T::sender ()
{
	return
	{
		this -> tcp_socket,
		this -> tls_context . get (),
		this -> socket_mutex,
		this -> spurious_read
	};
}
