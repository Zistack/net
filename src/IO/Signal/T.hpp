T::T () : fired (false)
{
	const std::string message_prefix = "IO::Signal::T\n";

	try
	{
		int fd [2];

		if (pipe (fd) == -1)
		{
			throw ResourceError::T ("pipe: " + strerror (errno) + "\n");
		}

		this -> read_fd = fd [0];
		this -> write_fd = fd [1];
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
