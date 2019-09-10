T::T ()
{
	const std::string message_prefix = "Failed to create pipe\n";

	int file_descriptor [2];

	if (pipe (file_descriptor) == -1)
	{
		throw Failure::ResourceError::T
		(
			message_prefix + "pipe: " + Failure::Util::strerror (errno) + "\n"
		);
	}

	this->read_file_descriptor = file_descriptor [0];
	this->write_file_descriptor = file_descriptor [1];

	try
	{
		if
		(
			fcntl
			(
				this -> read_file_descriptor,
				F_SETFL,
				fcntl (this -> read_file_descriptor, F_GETFL) | O_NONBLOCK
			) == -1
		)
		{
			throw Failure::ResourceError::T
			(
				message_prefix +
					"fcntl: " +
					Failure::Util::strerror (errno) +
					"\n"
			);
		}

		if
		(
			fcntl
			(
				this -> write_file_descriptor,
				F_SETFL,
				fcntl (this->write_file_descriptor, F_GETFL) | O_NONBLOCK
			) == -1
		)
		{
			throw Failure::ResourceError::T
			(
				message_prefix +
					"fcntl: " +
					Failure::Util::strerror (errno) +
					"\n"
			);
		}
	}
	catch (Failure::ResourceError::T)
	{
		close (this -> read_file_descriptor);
		close (this -> write_file_descriptor);
		throw;
	}
}

T::T (T && other)
:	read_file_descriptor (other . read_file_descriptor),
	write_file_descriptor (other . write_file_descriptor)
{
	other . read_file_descriptor = -1;
	other . write_file_descriptor = -1;
}
