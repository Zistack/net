void
setNonblocking (int file_descriptor)
{
	const std::string message_prefix =
		"Failed to set file descriptor as non-blocking\n";

	if
	(
		fcntl
		(
			file_descriptor,
			F_SETFL,
			fcntl (file_descriptor, F_GETFL) | O_NONBLOCK
		) == -1
	)
	{
		throw Failure::ResourceError::T
		(
			message_prefix +
				"fcntl: " +
				Failure::Util::strerror (errno) +
				"\n"
		);
	}
}
