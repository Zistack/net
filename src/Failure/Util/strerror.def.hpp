std::string
strerror (int errnum)
{
	// The man page for strerror says that this is a big enough buffer.
	const size_t BUFFER_LEN = 1024;
	char message [BUFFER_LEN];

#if (_POSIX_C_SOURCE >= 200112L) && ! _GNU_SOURCE
	strerror_r (errnum, message, BUFFER_LEN);
	return std::string (message);
#else
	return std::string (strerror_r (errnum, message, BUFFER_LEN));
#endif
}
