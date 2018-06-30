std::string
getString (IO::Interface::InputStream::T * input_stream)
{
	const std::string message_prefix = "Failed to parse string:\n";

	std::string value;

	try
	{
		Util::expect (input_stream, '"');

		while (true)
		{
			char c = input_stream -> get ();

			if (Class::control (c))
			{
				throw Error::T (Error::unpexectedCharacter (c, e));
			}

			if (c == '"') return value;

			if (c == '\\')
			{
				c = input_stream -> get ();

				switch (c)
				{
				case 'b':
					value.push_back ('\x08');
					continue;
				case 't':
					value.push_back ('\x09');
					continue;
				case 'n':
					value.push_back ('\x0A');
					continue;
				case 'f':
					value.push_back ('\x0C');
					continue;
				case 'r':
					value.push_back ('\x0D');
					continue;
				case 'u':
					value.append (IO::Util::runeToUTF8CodePoint (getEscape (input_stream)));
					continue;
				default:
					value.push_back (c);
					continue;
				}
			}

			value.push_back (c);
		}
	}
	catch (IO::Error::T e) throw Error::T (message_prefix + e.what ());
	catch (IO::EOF::T e)
	{
		throw Error::T (message_prefix + Error::unexpectedEOF ());
	}
	catch (Error::T) throw Error::T (message_prefix + e.what ());
}
