struct T
{
	T (const std::string & cipher_string);

	~T ();

	static void
	apply (gnutls_session_t session, const T & ciphers);

private:

	gnutls_priority_t m_priority;
};
