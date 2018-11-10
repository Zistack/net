std::pair<std::unique_ptr<char[]>, int>
T::newTempFile (const std::string & pattern)
{
	const std::string message_prefix = "IO::TempFile::T::newTempFile\n";

	std::unique_ptr<char[]> name =
	    std::make_unique<char[]> (pattern.size () + 1);
	int file_descriptor = mkstemp (name.get ());

	if (file_descriptor == -1)
	{
		throw Failure::Error::T (
		    message_prefix + "mkstemp: " + strerror (errno) + "\n");
	}

	return {std::move (name), file_descriptor};
}
