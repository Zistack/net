T::T ()
{
	const std::string message_prefix = "IO::Signal::T::T\n";

	this->file_descriptor = eventfd (0, EFD_SEMAPHORE | EFD_NONBLOCK);

	if (this->file_descriptor == -1)
	{
		throw Failure::ResourceError::T (
		    message_prefix + "eventfd: " + strerror (errno) + "\n");
	}
}
