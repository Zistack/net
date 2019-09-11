std::unique_ptr <Connection::Socket::T>
T::accept ()
{
	return std::apply
	(
		[] (int tcp_socket, struct tls * tls_context)
		{
			return std::make_unique <Connection::Socket::T>
			(
				tcp_socket,
				tls_context
			);
		},
		Util::accept (this -> m_tcp_socket, this -> m_tls_context . get ())
	);
}
