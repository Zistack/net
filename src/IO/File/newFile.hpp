int
T::newFile (const std::string & filename, const std::string & mode)
{
	const std::string message_prefix = "IO::File::T::newFile\n";

	int flags = 0;

	if (mode == "r")
	{
		flags = O_RDONLY;
	}
	if (mode == "w")
	{
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	}
	if (mode == "a")
	{
		flags = O_WRONLY | O_CREAT | O_APPEND;
	}
	if (mode == "r+")
	{
		flags = O_RDWR;
	}
	if (mode == "w+")
	{
		flags = O_RDWR | O_CREAT | O_TRUNC;
	}
	if (mode == "a+")
	{
		flags = O_RDWR | O_CREAT | O_APPEND;
	}

	int file_descriptor = open (filename.data (), flags);

	if (file_descriptor == -1)
	{
		throw Failure::Error::T (
		    message_prefix + "open: " + strerror (errno) + "\n");
	}

	return file_descriptor;
}
