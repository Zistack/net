std::string
getVChars (IO::PeekableInputStream::T & input_stream)
{
	const std::string message_prefix = "HTTP::Rule::getVChars\n";

	try
	{
		std::string vchars;

		while (IO::Util::test (input_stream, Class::vchar))
		{
			vchars.push_back (input_stream.get ());
		}

		if (!vchars.empty ()) return vchars;

		throw Failure::Error::T (IO::Message::unexpectedCharacter (input_stream.peek ());
	}
	catch (IO::EOF::T)
	{
		if (!vchars.epmty ()) return vchars;

		throw Failure::Error::T (message_prefix + IO::Message::unexpectedEOF ())
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
