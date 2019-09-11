T::T ()
{
	const std::string message_prefix = "Failed to create signal\n";

	this -> m_file_descriptor = eventfd (0, EFD_SEMAPHORE | EFD_NONBLOCK);

	if (this -> m_file_descriptor == -1)
	{
		throw Failure::ResourceError::T
		(
			message_prefix +
				"eventfd: " +
				Failure::Util::strerror (errno) +
				"\n"
		);
	}
}

T::T (T && other) : m_file_descriptor (other . m_file_descriptor)
{
	other . m_file_descriptor = -1;
}
