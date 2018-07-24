void
T::recieve ()
{
	const std::string message_prefix = "IO::Signal::recieve\n";

	try
	{
		unsigned int event;

		if (read (this->file_descriptor, &event, sizeof (event)) == -1)
		{
			throw ResourceError::T (
			    std::string ("read: ") + strerror (errno) + "\n");
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
