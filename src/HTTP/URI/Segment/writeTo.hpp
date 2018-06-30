void
T::writeTo (IO::Interface::OutputStream::T <char> * output_stream)
{
	const std::string message_prefix = "HTTP::URI::Segment::writeTo\n";

	try
	{
		Rule::putPChars (name);

		for (std::string parameter : parameters)
		{
			output_stream -> put (';');

			Rule::putPChars (parameter);
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
