T::T ()
{
	const std::string message_prefix = "IO::Pipe::T\n";

	try
	{
		int file_descriptor[2];

		if (pipe (file_descriptor) == -1)
		{
			throw Failure::ResourceError::T (
			    std::string ("pipe: ") + strerror (errno) + "\n");
		}

		this->read_file_descriptor = file_descriptor[0];
		this->write_file_descriptor = file_descriptor[1];

		try
		{
			if (fcntl (this->read_file_descriptor,
			        F_SETFL,
			        fcntl (this->read_file_descriptor, F_GETFL) | O_NONBLOCK) ==
			    -1)
			{
				throw Failure::ResourceError::T (
				    std::string ("fcntl: ") + strerror (errno) + "\n");
			}

			if (fcntl (this->write_file_descriptor,
			        F_SETFL,
			        fcntl (this->write_file_descriptor, F_GETFL) |
			            O_NONBLOCK) == -1)
			{
				throw Failure::ResourceError::T (
				    std::string ("fcntl: ") + strerror (errno) + "\n");
			}

			this->input_stream = new IO::FileDescriptor::InputStream::T (
			    this->read_file_descriptor);
			this->output_stream = new IO::FileDescriptor::OutputStream::T (
			    this->write_file_descriptor);
		}
		catch (const Failure::Throwable::T & e)
		{
			close (this->read_file_descriptor);
			close (this->write_file_descriptor);
			throw e;
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
