T::T (const std::string & filename, const std::string & mode) :
    input_stream (nullptr),
    output_stream (nullptr)
{
	const std::string message_prefix = "IO::File::T::T\n";

	int flags = 0;
	bool read = false;
	bool write = false;

	if (mode == "r")
	{
		flags = O_RDONLY;
		read = true;
	}
	if (mode == "w")
	{
		flags = O_WRONLY | O_CREAT | O_TRUNC;
		write = true;
	}
	if (mode == "a")
	{
		flags = O_WRONLY | O_CREAT | O_APPEND;
		write = true;
	}
	if (mode == "r+")
	{
		flags = O_RDWR;
		read = true;
		write = true;
	}
	if (mode == "w+")
	{
		flags = O_RDWR | O_CREAT | O_TRUNC;
		read = true;
		write = true;
	}
	if (mode == "a+")
	{
		flags = O_RDWR | O_CREAT | O_APPEND;
		read = true;
		write = true;
	}

	this->file_descriptor = open (filename.data (), flags);

	if (this->file_descriptor == -1)
	{
		throw Failure::Error::T (
		    message_prefix + "open: " + strerror (errno) + "\n");
	}

	if (read)
	{
		this->input_stream =
		    new FileDescriptor::InputStream::T (this->file_descriptor);
	}

	if (write)
	{
		this->output_stream =
		    new FileDescriptor::OutputStream::T (this->file_descriptor);
	}
}
