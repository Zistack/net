T::T () : fired (false)
{
	const std::string message_prefix = "IO::Signal::T\n";

	try
	{
		int file_descriptor[2];

		if (pipe (file_descriptor) == -1)
		{
			throw ResourceError::T (
			    std::string ("pipe: ") + strerror (errno) + "\n");
		}

		this->read_file_descriptor = file_descriptor[0];
		this->write_file_descriptor = file_descriptor[1];
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
