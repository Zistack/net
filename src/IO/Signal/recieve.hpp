bool
T::recieve ()
{
	const std::string message_prefix = "IO::Signal::T::recieve\n";

	try
	{
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
				throw Failure::ResourceError::T (
				    std::string ("read: ") + strerror (errno) + "\n");
			}
		}

		return true;
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
