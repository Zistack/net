void
T::put (CharType c)
{
	const std::string message_prefix = "IO::Cancellable::OutputStream::put\n";

	try
	{
		Watchable::T * ready_stream = this -> epoll -> wait ();

		if (ready_stream == this -> output_stream)
		{
			this -> output_stream -> put (c);
		}
		else if (ready_stream == this -> signal)
		{
			throw CancelError::T ("Operation cancelled\n");
		}
	}
	catch (Failure::Throwable::T e) throw e.set (message_prefix + e.what ());
}
