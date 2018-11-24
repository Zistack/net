struct T
{
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

	protected:
	void
	setCAPath (const std::string & ca_path);

	bool
	setCAPath (const JSON::Object::T & config_object);

	void
	setIdentity (const std::string & private_key_filename,
	    const std::string & certificate_filename);

	bool
	setIdentity (const JSON::Object::T & config_object);

	private:
	std::unique_ptr<struct tls_config, Functor::T<tls_config_free>> tls_config;

	friend ConfigurableContext::T;
};
