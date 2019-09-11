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

	this -> m_read_file_descriptor = file_descriptor [0];
	this -> m_write_file_descriptor = file_descriptor [1];

	try
	{
		if
		(
			fcntl
			(
				this -> m_read_file_descriptor,
				F_SETFL,
				fcntl (this -> m_read_file_descriptor, F_GETFL) | O_NONBLOCK
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
				this -> m_write_file_descriptor,
				F_SETFL,
				fcntl (this -> m_write_file_descriptor, F_GETFL) | O_NONBLOCK
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
		close (this -> m_read_file_descriptor);
		close (this -> m_write_file_descriptor);
		throw;
	}
}

T::T (T && other)
:	m_read_file_descriptor (other . m_read_file_descriptor),
	m_write_file_descriptor (other . m_write_file_descriptor)
{
	other . m_read_file_descriptor = -1;
	other . m_write_file_descriptor = -1;
}
