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
		Util::setNonblocking (this -> m_read_file_descriptor);
		Util::setNonblocking (this -> m_write_file_descriptor);
	}
	catch (Failure::ResourceError::T & e)
	{
		close (this -> m_read_file_descriptor);
		close (this -> m_write_file_descriptor);
		throw Failure::ResourceError::T (message_prefix + e . what ());
	}
}

T::T (T && other)
:	m_read_file_descriptor (other . m_read_file_descriptor),
	m_write_file_descriptor (other . m_write_file_descriptor)
{
	other . m_read_file_descriptor = -1;
	other . m_write_file_descriptor = -1;
}
