void
skipWhitespace (IO::Interface::PeekableInputStream::T <char> * input_stream)
{
	const std::string message_prefix = "HTTP::Util::skipWhitespace\n";

	try
	{
		while (IO::Util::test (input_stream, Class::whitespace))
		{
			input_stream->get ();
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
