off_t
T::size () const
{
	const std::string message_prefix = "Failed to stat temporary file\n";

	struct stat file_status;

	if (fstat (this -> file_descriptor, & file_status) == -1)
	{
		throw Failure::ResourceError::T
		(
			message_prefix + "fstat: " + strerror (errno) + "\n"
		);
	}

	return file_status . st_size;
}
