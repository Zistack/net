size_t
T::read (char * buffer, size_t count)
{
	const std::string message_prefix =
	    "IO::FileDescriptor::InputStream::T::read\n";

	try
	{
		while (true)
		{
			ssize_t size = ::read (this->file_descriptor, buffer, count);

			if (size == 0) throw EOF::T ();

			if (size == -1)
			{
				const std::string message =
				    std::string ("read: ") + strerror (errno) + "\n";

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
