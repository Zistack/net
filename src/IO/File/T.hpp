T::T (const std::string & filename, const std::string & mode)
{
	const std::string message_prefix = "Failed to open file\n";

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

	this->file_descriptor = open (filename.data (), flags);

	if (this->file_descriptor == -1)
	{
		throw Failure::ResourceError::T (
		    message_prefix + "open: " + strerror (errno) + "\n");
	}
}

T::T (T && other) : file_descriptor (other.file_descriptor)
{
	other.file_descriptor = -1;
}
