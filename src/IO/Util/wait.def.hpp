template <typename Stream, typename CancelSignal>
void
wait (Stream && stream, CancelSignal && cancel_signal)
{
	const std::string message_prefix = "Failed to wait for resource:\n";

	struct pollfd fds[2] =
	{
		{
			.fd = stream . fileDescriptor (),
			.events = stream . events (),
			.revents = 0
		},
		{
			.fd = cancel_signal . fileDescriptor (),
			.events = cancel_signal . events (),
			.revents = 0
		}
	};

	while (poll (fds, 2, -1) == -1)
	{
		switch (errno)
		{
		case EAGAIN:
		case EINTR:

			continue;

		case EINVAL:
		default:

			throw Failure::ResourceError::T
			(
				message_prefix + "poll: " + strerror (errno) + "\n"
			);
		}
	}

	if (fds [1] . revents) throw Failure::CancelException::T ();
}

template <typename Stream>
void
wait (Stream && stream)
{
	const std::string message_prefix = "Failed to wait for resource:\n";

	struct pollfd fds [1] =
	{
		{
			.fd = stream . fileDescriptor (),
			.events = stream . events (),
			.revents = 0
		}
	};

	while (poll (fds, 1, -1) == -1)
	{
		switch (errno)
		{
		case EAGAIN:
		case EINTR:

			continue;

		case EINVAL:
		default:

			throw Failure::ResourceError::T
			(
				message_prefix + "poll: " + strerror (errno) + "\n"
			);
		}
	}
}
