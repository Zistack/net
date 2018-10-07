T::T (IO::Interface::PeekableInputStream::T * input_stream)
{
	const std::string message_prefix = "JSON::String::T\n";

	try
	{
		IO::Util::expect (input_stream, '"');

		while (true)
		{
			char c = input_stream->get ();

			if (Class::control (c))
			{
				throw Failure::Error::T (IO::Message::unexpectedCharacter (c));
			}

			if (c == '"') return;

			if (c == '\\')
			{
				c = input_stream->get ();

				switch (c)
				{
				case 'b':
					this->value.push_back ('\x08');
					continue;
				case 't':
					this->value.push_back ('\x09');
					continue;
				case 'n':
					this->value.push_back ('\x0A');
					continue;
				case 'f':
					this->value.push_back ('\x0C');
					continue;
				case 'r':
					this->value.push_back ('\x0D');
					continue;
				case 'u':
					this->value.append (IO::Util::runeToUTF8CodePoint (
					    Rule::getEscape (input_stream)));
					continue;
				default:
					this->value.push_back (c);
					continue;
				}
			}

			this->value.push_back (c);
		}
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

T::T (const std::string & string) : value (string) {}
