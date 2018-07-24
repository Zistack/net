void
T::put (char c)
{
	const std::string message_prefix = "IO::Cancellable::OutputStream::put\n";

	try
	{
		Util::wait (this->output_stream, this->signal);

		this->output_stream->put (c);
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
