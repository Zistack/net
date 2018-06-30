T::T ()
{
	const std::string message_prefix = "IO::Epoll::T\n";

	try
	{
		this -> fd = epoll_create (1);

		if (this -> fd == -1)
		{
			throw ResourceError::T ("epoll_create: " + strerror (errno) + "\n");
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
