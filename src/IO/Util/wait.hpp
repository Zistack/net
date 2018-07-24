void
wait (Interface::Watchable::T * watchable, Signal::T * signal)
{
	const std::string message_prefix = "IO::Util::Wait\n";

	try
	{
		struct pollfd fds[2] = {{.fd = watchable->fileDescriptor (),
		                            .events = watchable->events ()},
		    {.fd = signal->fileDescriptor (), .events = watchable->events ()}};

		while (poll (fds, 2, 0) == -1)
		{
			switch (errno)
			{
			case EAGAIN:
			case EINTR:
				continue;
			case EINVAL:
			default:
				throw ResourceError::T (
				    std::string ("poll: ") + strerror (errno) + "\n");
			}
		}

		if (fds[1].revents)
		{
			signal->recieve ();
			throw CancelError::T ("Operation cancelled\n");
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
