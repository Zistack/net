void
setMaxRecordSize (gnutls_session_t session, size_t max_record_size)
{
	ssize_t err = gnutls_record_set_max_recv_size (session, max_record_size);
	if (err != GNUTLS_E_SUCCESS)
	{
		throw Failure::Error::T
		(
			std::string
			(
				"Failed to set max record size to negotiate on client session: "
			) +
				gnutls_strerror ((int) err) +
				"\n"
		);
	}
}
