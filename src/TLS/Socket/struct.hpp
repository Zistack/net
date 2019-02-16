struct T
{
	T (const T & other) = delete;

	T (T && other) = default;

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other) = default;

	virtual ~T ();

	protected:
	T (int tcp_socket, struct tls * tls_context);

	T (std::pair<int, struct tls *> p);

	int tcp_socket;
	std::unique_ptr<struct tls, Functor::T<tls_free>> tls_context;
};