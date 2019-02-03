struct T : TLS::ConnectionSocket::T
{
	T (std::pair<int, struct tls *> p);

	~T () = default;
};
