char
T::get ()
{
	const std::string message_prefix = "IO::Cancellable::InputStream::get\n";

	try
	{
		Interface::Watchable::T * ready_stream = this->epoll->wait ();

		if (ready_stream == this->input_stream)
		{
			return this->input_stream->get ();
		}
		else if (ready_stream == this->signal)
		{
			throw CancelError::T ("Operation cancelled\n");
		}
	}
	catch (Failure::Throwable::T e)
	{
		throw e.set (message_prefix + e.what ());
	}

	return 0; // Unreachable.
}
