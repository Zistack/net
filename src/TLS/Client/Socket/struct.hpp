struct T : TLS::ConfigurableSocket::T, TLS::ConnectionSocket::T
{
	T (const Config::T & config);

	T (const T & other) = delete;
	T (T && other) = delete;

	T &
	operator= (const T & other) = delete;
	T &
	operator= (T && other) = delete;

	~T () = default;
};
