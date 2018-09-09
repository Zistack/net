off_t
T::size ()
{
	const std::string message_prefix = "IO::TempFile::T::size\n";

	struct stat file_status;

	if (fstat (this->file_descriptor, &file_status) == -1)
	{
		throw Failure::Error::T (
		    message_prefix + "fstat: " + strerror (errno) + "\n");
	}

	return file_status.st_size;
}
