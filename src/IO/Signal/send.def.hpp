void
T::send ()
{
	const std::string message_prefix = "Failed to send event\n";

	uint64_t event = 1;

	if (write (this -> file_descriptor, & event, sizeof (event)) == -1)
	{
		throw Failure::ResourceError::T
		(
			message_prefix + "write: " + Failure::Util::strerror (errno) + "\n"
		);
	}
}
