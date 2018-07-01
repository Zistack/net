void
T::shutdown (Direction::T direction)
{
	const std::string message_prefix = "IO::Socket::shutdown\n";

	try
	{
		int how = 0;

		if (direction == Direction::READ) how = SHUT_RD;
		if (direction == Direction::WRITE) how = SHUT_WR;
		if (direction == (Direction::READ | Direction::WRITE)) how = SHUT_RDWR;

		if (::shutdown (this->file_descriptor, how) == -1)
		{
			throw ResourceError::T (
			    std::string ("shutdown: ") + strerror (errno) + "\n");
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
