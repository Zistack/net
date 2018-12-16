std::pair<int, int>
T::newPipe ()
{
	const std::string message_prefix = "IO::Pipe::T::newPipe\n";

	int file_descriptor[2];

	if (pipe (file_descriptor) == -1)
	{
		throw Failure::ResourceError::T (
		    message_prefix + "pipe: " + strerror (errno) + "\n");
	}

	int read_file_descriptor = file_descriptor[0];
	int write_file_descriptor = file_descriptor[1];

	try
	{
		if (fcntl (read_file_descriptor,
		        F_SETFL,
		        fcntl (read_file_descriptor, F_GETFL) | O_NONBLOCK) == -1)
		{
			throw Failure::ResourceError::T (
			    message_prefix + "fcntl: " + strerror (errno) + "\n");
		}

		if (fcntl (write_file_descriptor,
		        F_SETFL,
		        fcntl (write_file_descriptor, F_GETFL) | O_NONBLOCK) == -1)
		{
			throw Failure::ResourceError::T (
			    message_prefix + "fcntl: " + strerror (errno) + "\n");
		}
	}
	catch (Failure::ResourceError::T)
	{
		close (read_file_descriptor);
		close (write_file_descriptor);
		throw;
	}

	return {read_file_descriptor, write_file_descriptor};
}
