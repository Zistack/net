struct T
{
	T ();

	T (int tcp_socket, struct tls * tls_context);

	T (T && other);

	T &
	operator = (T && other);

	virtual ~T ();

protected:

	int m_tcp_socket;
	std::unique_ptr <struct tls, Functor::T <tls_free>> m_tls_context;
};
