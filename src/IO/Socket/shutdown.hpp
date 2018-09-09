void
T::shutdown (Direction::T direction)
{
	const std::string message_prefix = "IO::Socket::T::shutdown\n";

	int how = 0;

	if (direction == Direction::READ) how = SHUT_RD;
	if (direction == Direction::WRITE) how = SHUT_WR;
	if (direction == (Direction::READ | Direction::WRITE)) how = SHUT_RDWR;

	if (::shutdown (this->file_descriptor, how) == -1)
	{
		throw Failure::Error::T (
		    message_prefix + "shutdown: " + strerror (errno) + "\n");
	}
}
