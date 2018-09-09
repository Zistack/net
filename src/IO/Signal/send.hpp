void
T::send ()
{
	const std::string message_prefix = "IO::Signal::T::send\n";

	uint64_t event = 1;

	if (write (this->file_descriptor, &event, sizeof (event)) == -1)
	{
		throw Failure::Error::T (
		    message_prefix + "write: " + strerror (errno) + "\n");
	}
}
