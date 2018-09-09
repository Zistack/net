void
wait (Interface::Watchable::T * watchable, Signal::T * signal)
{
	const std::string message_prefix = "IO::Util::Wait\n";

	struct pollfd fds[2] = {{.fd = watchable->fileDescriptor (),
	                            .events = watchable->events (),
	                            .revents = 0},
	    {.fd = signal->fileDescriptor (),
	        .events = signal->events (),
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
			throw Failure::Error::T (
			    message_prefix + "poll: " + strerror (errno) + "\n");
		}
	}

	if (fds[1].revents)
	{
		signal->recieve ();
		throw Failure::CancelException::T ();
	}
}

void
wait (Interface::Watchable::T * watchable)
{
	const std::string message_prefix = "IO::Util::Wait\n";

	struct pollfd fd = {.fd = watchable->fileDescriptor (),
	    .events = watchable->events (),
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
			throw Failure::Error::T (
			    message_prefix + "poll: " + strerror (errno) + "\n");
		}
	}
}
