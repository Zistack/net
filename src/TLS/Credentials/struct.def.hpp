struct T
{
	static void
	apply (gnutls_session_t session, const T & credentials);

protected:

	T ();

	T (const T & other) = delete;

	T (T && other) = delete;

	T &
	operator = (const T & other) = delete;

	T &
	operator = (T && other) = delete;

	void
	setIdentity
	(
		const URI::Path::T & certificate_file,
		const URI::Path::T & private_key_file
	);

	void
	setCAPath (const URI::Path::T & ca_path);

	~T ();

private:

	gnutls_certificate_credentials_t m_credentials;
};
