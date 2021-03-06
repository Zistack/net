bool
T::recieve ()
{
	const std::string message_prefix = "Failed to recieve event\n";

	uint64_t event;

	while (read (this -> m_file_descriptor, & event, sizeof (event)) == -1)
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

			throw Failure::ResourceError::T
			(
				message_prefix +
					"read: " +
					Failure::Util::strerror (errno) +
					"\n"
			);
		}
	}

	return true;
}
