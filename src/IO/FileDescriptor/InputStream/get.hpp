char
T::get ()
{
	const std::string message_prefix = "IO::FileDescriptor::InputStream::get\n";

	try
	{
		while (true)
		{
			char c;
			ssize_t size = read (this->file_descriptor, &c, 1);

			if (size == 0) throw EOF::T ();

			if (size == -1)
			{
				const std::string message =
				    std::string ("read: ") + strerror (errno) + "\n";

				switch (errno)
				{
				case EAGAIN:
				// case EWOULDBLOCK: // Apparently a duplicate of EAGAIN.
				case EINTR:
					continue;
				case EBADF:
				case EFAULT:
				case EINVAL:
				case EIO:
				case EISDIR:
				default:
					throw ResourceError::T (message);
				}
			}

			return c;
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
