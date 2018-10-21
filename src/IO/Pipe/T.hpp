T::T () : is_shutdown (false)
{
	const std::string message_prefix = "IO::Pipe::T::T\n";

	int file_descriptor[2];

	if (pipe (file_descriptor) == -1)
	{
		throw Failure::Error::T (
		    message_prefix + "pipe: " + strerror (errno) + "\n");
	}

	this->read_file_descriptor = file_descriptor[0];
	this->write_file_descriptor = file_descriptor[1];

	try
	{
		if (fcntl (this->read_file_descriptor,
		        F_SETFL,
		        fcntl (this->read_file_descriptor, F_GETFL) | O_NONBLOCK) == -1)
		{
			throw Failure::Error::T (
			    message_prefix + "fcntl: " + strerror (errno) + "\n");
		}

		if (fcntl (this->write_file_descriptor,
		        F_SETFL,
		        fcntl (this->write_file_descriptor, F_GETFL) | O_NONBLOCK) ==
		    -1)
		{
			throw Failure::Error::T (
			    message_prefix + "fcntl: " + strerror (errno) + "\n");
		}

		this->input_stream =
		    new IO::FileDescriptor::InputStream::T (this->read_file_descriptor);
		this->output_stream = new IO::FileDescriptor::OutputStream::T (
		    this->write_file_descriptor);
	}
	catch (Failure::Error::T)
	{
		close (this->read_file_descriptor);
		close (this->write_file_descriptor);
		throw;
	}
}
