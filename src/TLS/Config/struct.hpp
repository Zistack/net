struct T
{
	protected:
	// Revocation and cipher strings are things that we might want to configure,
	// but we can worry about them later.

	T ();

	T (const T & other) = delete;

	T (T && other) = default;

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other) = default;

	virtual ~T () = default;

	void
	setCAPath (const std::string & ca_path);

	void
	setIdentity (const std::string & private_key_filename,
	    const std::string & certificate_filename);

	std::unique_ptr<struct tls_config,
	    Functor::T<decltype (tls_config_free), tls_config_free>>
	    tls_config;

	friend ConfigurableContext::T;
};
