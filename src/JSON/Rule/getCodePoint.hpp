char16_t
getCodePoint (IO::Interface::InputStream::T <char> * input_stream)
{
	const std::string message_prefix = "Failed to parse code point:\n";

	char c;
	char16_t code_point = 0;

	try
	{
		unsigned int i;
		for (i = 4; i > 0; --i)
		{
			c = IO::Util::expect (input_stream, IO::Class::hex);

			code_point |= ((char16_t) IO::Util::hexToNibble (c)) << ((i - 1) * 4);
		}

		return code_point;
	}
	catch (IO::Error::T e) throw Error::T (message_prefix + e.what ());
	catch (IO::EOF::T e)
	{
		throw Error::T (message_prefix + Error::unexpectedEOF ());
	}
	catch (Error::T e) throw Error::T (message_prefix + e.what ());
}
