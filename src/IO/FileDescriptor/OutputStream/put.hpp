void
T::put (char c)
{
	const std::string message_prefix =
	    "IO::FileDescriptor::OutputStream::write\n";

	try
	{
		while (true)
		{
			ssize_t size = write (this->file_descriptor, &c, 1);

			if (size == 0)
			{
				continue;
			}

			if (size == -1)
			{
				const std::string message =
				    std::string ("write: ") + strerror (errno) + "\n";

				switch (errno)
				{
				case EAGAIN:
				// case EWOULDBLOCK: // Apparently a duplicate of EAGAIN.
				case EINTR:
					continue;
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
					throw ResourceError::T (message);
				}
			}

			return;
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
