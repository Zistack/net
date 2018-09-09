size_t
T::read (char * buffer, size_t count)
{
	const std::string message_prefix =
	    "IO::FileDescriptor::InputStream::T::read\n";

	while (true)
	{
		ssize_t size = ::read (this->file_descriptor, buffer, count);

		if (size == 0) throw EOF::T ();

		if (size == -1)
		{
			switch (errno)
			{
			case EAGAIN:
#if EWOULDBLOCK != EAGAIN
			case EWOULDBLOCK:
#endif
			case EINTR:
				return 0;
			case EBADF:
			case EFAULT:
			case EINVAL:
			case EIO:
			case EISDIR:
			default:
				throw Failure::Error::T (
				    message_prefix + "read: " + strerror (errno) + "\n");
			}
		}

		return (size_t) size;
	}
}
