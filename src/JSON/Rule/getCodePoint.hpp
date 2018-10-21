char16_t
getCodePoint (IO::Interface::InputStream::T * input_stream)
{
	const std::string message_prefix = "JSON::Rule::getCodePoint\n";

	char c;
	char16_t code_point = 0;

	try
	{
		unsigned int i;
		for (i = 4; i > 0; --i)
		{
			c = IO::Util::expect (input_stream, IO::Class::hex);

			code_point |=
			    (char16_t) (IO::Util::hexToNibble (c) << ((i - 1) * 4));
		}

		return code_point;
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
	catch (const IO::EOF::T & e)
	{
		throw Failure::Error::T (
		    message_prefix + IO::Message::unexpectedEOF ());
	}
}
