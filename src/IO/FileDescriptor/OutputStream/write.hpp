size_t
T::write (const char * buffer, size_t count)
{
	const std::string message_prefix =
	    "IO::FileDescriptor::OutputStream::T::write\n";

	while (true)
	{
		ssize_t size = ::write (this->file_descriptor, buffer, count);

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
			case EDESTADDRREQ:
			case EDQUOT:
			case EFAULT:
			case EFBIG:
			case EINVAL:
			case EIO:
			case ENOSPC:
			case EPERM:
			case EPIPE:
			default:
				throw Failure::ResourceError::T (
				    message_prefix + "write: " + strerror (errno) + "\n");
			}
		}

		return (size_t) size;
	}
}
