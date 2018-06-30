Error::T
deserialize (std::istream * json_stream, std::string * value)
{
	Error::T ret;
	skipWhitespace (json_stream);

	std::char_traits<char>::int_type c = json_stream->get ();

	if (eof (c)) return Error::UNEXPECTED_EOF;

	if (c != '"') return Error::NOT_A_STRING;

	do
	{
		c = json_stream->get ();

		if (c < '\x20') return Error::INVALID_CHARACTER;

		if (eof (c)) return Error::UNEXPECTED_EOF;
		if (c == '"') return 0;

		if (c == '\\')
		{
			c = json_stream->get ();

			if (eof (c)) return Error::UNEXPECTED_EOF;

			switch (c)
			{
			case 'b':
				value->push_back ('\x08');
				continue;
			case 't':
				value->push_back ('\x09');
				continue;
			case 'n':
				value->push_back ('\x0A');
				continue;
			case 'f':
				value->push_back ('\x0C');
				continue;
			case 'r':
				value->push_back ('\x0D');
				continue;
			case 'u':
				if ((ret = decode (json_stream, value))) return ret;
				continue;
			default:
				value->push_back ((char) c);
				continue;
			}
		}

		value->push_back ((char) c);
	} while (true);

	return Error::NONE;
}
