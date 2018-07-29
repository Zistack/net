off_t
T::size ()
{
	const std::string message_prefix = "IO::TempFile::size\n";

	try
	{
		struct stat file_status;

		if (fstat (this->file_descriptor, &file_status) == -1)
		{
			throw Failure::ResourceError::T (
			    std::string ("fstat: ") + strerror (errno) + "\n");
		}

		return file_status.st_size;
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
