void
T::reset ()
{
	const std::string message_prefix = "IO::TempFile::reset\n";

	try
	{
		if (lseek (this->file_descriptor, 0, SEEK_SET) == -1)
		{
			throw Failure::ResourceError::T (
			    std::string ("lseek: ") + strerror (errno) + "\n");
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
