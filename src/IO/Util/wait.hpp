template <class Stream, class... CancelSignals>
void
wait (Stream && stream, CancelSignals &&... cancel_signals)
{
	const std::string message_prefix = "IO::Util::wait\n";

	size_t num_watchables = 1 + sizeof...(cancel_signals);

	struct pollfd fds[num_watchables];
	fds[0] = {.fd = stream.fileDescriptor (),
	    .events = stream.events (),
	    .revents = 0};

	int i = 1;
	(waitLoad (cancel_signals, fds, i), ...);

	while (poll (fds, num_watchables, -1) == -1)
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

	for (i = 1; i < num_watchables; ++i)
	{
		if (fds[i].revents) throw Failure::CancelException::T ();
	}
}

template <class Stream>
void
wait (Stream && stream,
    std::initializer_list<std::reference_wrapper<Interface::Watchable::T>>
        cancel_signals)
{
	const std::string message_prefix = "IO::Util::wait\n";

	size_t num_watchables = 1 + cancel_signals.size ();

	struct pollfd fds[num_watchables];
	fds[0] = {.fd = stream.fileDescriptor (),
	    .events = stream.events (),
	    .revents = 0};

	int i = 1;
	for (Interface::Watchable::T & cancel_signal : cancel_signals)
	{
		fds[i] = {.fd = cancel_signal.fileDescriptor (),
		    .events = cancel_signal.events (),
		    .revents = 0};
		++i;
	}

	while (poll (fds, num_watchables, -1) == -1)
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

	for (i = 1; i < num_watchables; ++i)
	{
		if (fds[i].revents) throw Failure::CancelException::T ();
	}
}
