std::string
strerror (int errnum)
{
	// The man page for strerror says that this is a big enough buffer.
	const size_t BUFFER_LEN = 1024;
	char message [BUFFER_LEN];

	// As long as we don't feed an invalid errnum into this function, we don't
	// have to worry about this call failing.
	strerror_r (errnum, message, BUFFER_LEN);

	return std::string (message);
}
