struct T
{
	T (struct tls * tls_context);

	T (const T & other) = delete;

	T (T && other) = default;

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other) = default;

	virtual ~T () = default;

	protected:
	std::unique_ptr<struct tls, Functor::T<tls_free>> tls_context;
};
