void
reset ()
{
	const std::string message_prefix = "IO::TempFile::reset\n";

	try
	{
		if (lseek (this -> fd, 0, SEEK_SET) == -1)
		{
			throw ResourceError::T ("lseek: " + strerror (errno) + "\n");
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
