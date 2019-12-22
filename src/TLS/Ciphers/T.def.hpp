T::T (const std::string & cipher_string)
{
	const char * err_pos = nullptr;
	int err = gnutls_priority_init
	(
		& this -> m_priority,
		cipher_string . data (),
		& err_pos
	);
	switch (err)
	{
	case GNUTLS_E_SUCCESS:

		return;

	case GNUTLS_E_INVALID_REQUEST:

		throw Failure::SyntaxError::T
		(
			std::string ("Syntax error in cipher string:\n") +
				cipher_string + "\n" +
				std::string
				(
					(std::string::size_type) (err_pos - cipher_string . data ()),
					' '
				) + "^\n"
		);

	default:

		throw Failure::Error::T
		(
			std::string ("Failed to initialize cipher cache: ") +
				gnutls_strerror (err) +
				"n"
		);
	}
}
