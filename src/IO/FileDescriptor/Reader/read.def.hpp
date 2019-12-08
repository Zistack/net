size_t
T::read (char * buffer, size_t count)
{
	while (true)
	{
		ssize_t size = pread
		(
			this -> m_file_descriptor,
			buffer,
			count,
			(off_t) this -> m_pointer
		);

		if (size == 0) throw Failure::EndOfResource::T ();

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
					std::string ("read: ") +
						Failure::Util::strerror (errno) +
						"\n"
				);
			}
		}

		this -> m_pointer += (size_t) size;

		return (size_t) size;
	}
}
