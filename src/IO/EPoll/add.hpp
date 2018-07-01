void
T::add (Interface::Watchable::T * watchable)
{
	const std::string message_prefix = "IO::Epoll::add\n";

	try
	{
		struct epoll_event ev;

		memset (&ev, 0, sizeof (ev));

		ev.events = watchable->events ();
		ev.data.ptr = watchable;

		if (epoll_ctl (this->file_descriptor,
		        EPOLL_CTL_ADD,
		        watchable->fileDescriptor (),
		        &ev))
		{
			throw ResourceError::T (
			    std::string ("epoll_ctl: ") + strerror (errno) + "\n");
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
