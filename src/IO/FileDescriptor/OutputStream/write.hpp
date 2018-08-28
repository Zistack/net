size_t
T::write (const char * buffer, size_t count)
{
	const std::string message_prefix =
	    "IO::FileDescriptor::OutputStream::write\n";

	try
	{
		while (true)
		{
			ssize_t size = ::write (this->file_descriptor, buffer, count);

			if (size == -1)
			{
				const std::string message =
				    std::string ("write: ") + strerror (errno) + "\n";

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
					throw Failure::ResourceError::T (message);
				}
			}

			return (size_t) size;
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
