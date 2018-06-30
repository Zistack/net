Watchable::T *
T::wait ()
{
	const std::string message_prefix = "IO::EPoll::wait\n";

	try
	{
		while (true)
		{
			struct epoll_event ev;

			if (epoll_wait (this -> fd, & ev, 1, -1) == -1)
			{
				const std::string message =
					"epoll_wait: " + strerror (errno) + "\n";

				switch (errno)
				{
				case EINTR:
					continue;
				case EBADF:
				case EFAULT:
				case EINVAL:
				default:
					throw ResourceError::T (message);
				}
			}

			return (Interface::Watchable::T *) ev.data.ptr;
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
