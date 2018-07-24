T::T ()
{
	const std::string message_prefix = "IO::Signal::T\n";

	try
	{
		this->file_descriptor = eventfd (0, EFD_SEMAPHORE);

		if (this->file_descriptor == -1)
		{
			throw ResourceError::T (
			    std::string ("eventfd: ") + strerror (errno) + "\n");
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
