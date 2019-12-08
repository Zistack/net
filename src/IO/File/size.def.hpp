size_t
T::size () const
{
	const std::string message_prefix = "Failed to stat file\n";

	struct stat file_status;

	if (fstat (this -> m_file_descriptor, & file_status) == -1)
	{
		throw Failure::ResourceError::T (
			message_prefix + "fstat: " + Failure::Util::strerror (errno) + "\n"
		);
	}

	return (size_t) file_status . st_size;
}
