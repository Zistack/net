void
T::send ()
{
	const std::string message_prefix = "IO::Signal::send\n";

	try
	{
		uint64_t event = 1;

		if (write (this->file_descriptor, &event, sizeof (event)) == -1)
		{
			throw Failure::ResourceError::T (
			    std::string ("write: ") + strerror (errno) + "\n");
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
