struct T : TLS::ConnectionSocket::T
{
	T (const Config::Value::T & config);

	T (const T & other) = delete;
	T (T && other) = delete;

	T &
	operator= (const T & other) = delete;
	T &
	operator= (T && other) = delete;

	~T () = default;

	private:
	T (int tcp_socket, struct tls * client_context);
	T (std::pair<int, struct tls *> p);
};
