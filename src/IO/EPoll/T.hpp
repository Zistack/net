T::T ()
{
	const std::string message_prefix = "IO::Epoll::T\n";

	try
	{
		this->file_descriptor = epoll_create (1);

		if (this->file_descriptor == -1)
		{
			throw ResourceError::T (
			    std::string ("epoll_create: ") + strerror (errno) + "\n");
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
