void
wait (Interface::Watchable::T & watchable, Signal::T & signal)
{
	const std::string message_prefix = "IO::Util::Wait\n";

	try
	{
		struct pollfd fds[2] = {{.fd = watchable.fileDescriptor (),
		                            .events = watchable.events (),
		                            .revents = 0},
		    {.fd = signal.fileDescriptor (),
		        .events = watchable.events (),
		        .revents = 0}};

		while (poll (fds, 2, -1) == -1)
		{
			switch (errno)
			{
			case EAGAIN:
			case EINTR:
				continue;
			case EINVAL:
			default:
				throw Failure::ResourceError::T (
				    std::string ("poll: ") + strerror (errno) + "\n");
			}
		}

		if (fds[1].revents)
		{
			signal.recieve ();
			throw Failure::CancelError::T ("Operation cancelled\n");
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}

void
wait (Interface::Watchable::T & watchable)
{
	const std::string message_prefix = "IO::Util::Wait\n";

	try
	{
		struct pollfd fd = {.fd = watchable.fileDescriptor (),
		    .events = watchable.events (),
		    .revents = 0};

		while (poll (&fd, 1, -1) == -1)
		{
			switch (errno)
			{
			case EAGAIN:
			case EINTR:
				continue;
			case EINVAL:
			default:
				throw Failure::ResourceError::T (
				    std::string ("poll: ") + strerror (errno) + "\n");
			}
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
