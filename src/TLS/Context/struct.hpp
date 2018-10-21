struct T
{
	virtual ~T () = default;

	protected:
	T (struct tls * tls_context);

	T (const T & other) = delete;

	T (T && other) = default;

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other) = default;

	std::unique_ptr<struct tls, Functor::T<decltype (tls_free), tls_free>>
	    tls_context;
};
