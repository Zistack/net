size_t
T::write (const char * buffer, size_t count)
{
	while (true)
	{
		ssize_t size = ::write (this -> file_descriptor, buffer, count);

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

			default:

				throw Failure::ResourceError::T
				(
					std::string ("write: ") +
						Failure::Util::strerror (errno) +
						"\n"
				);
			}
		}

		return (size_t) size;
	}
}
