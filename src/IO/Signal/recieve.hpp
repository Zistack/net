bool
T::recieve ()
{
	const std::string message_prefix = "IO::Signal::T::recieve\n";

	uint64_t event;

	while (read (this->file_descriptor, &event, sizeof (event)) == -1)
	{
		switch (errno)
		{
		case EINTR:
			continue;
		case EAGAIN:
#if EAGAIN != EWOULDBLOCK
		case EWOULDBLOCK:
#endif
			return false;
		case EBADF:
		case EFAULT:
		case EINVAL:
		case EIO:
		default:
			throw Failure::Error::T (
			    message_prefix + "read: " + strerror (errno) + "\n");
		}
	}

	return true;
}
