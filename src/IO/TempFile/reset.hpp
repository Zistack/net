void
T::reset ()
{
	const std::string message_prefix = "IO::TempFile::T::reset\n";

	if (lseek (this->file_descriptor, 0, SEEK_SET) == -1)
	{
		throw Failure::ResourceError::T (
		    message_prefix + "lseek: " + strerror (errno) + "\n");
	}
}
