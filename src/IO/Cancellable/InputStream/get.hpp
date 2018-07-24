char
T::get ()
{
	const std::string message_prefix = "IO::Cancellable::InputStream::get\n";

	try
	{
		Util::wait (this->input_stream, this->signal);

		return this->input_stream->get ();
	}
	catch (Failure::Throwable::T e)
	{
		throw e.set (message_prefix + e.what ());
	}

	return 0; // Unreachable.
}
