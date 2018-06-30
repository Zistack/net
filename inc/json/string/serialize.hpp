Error::T
serialize (std::string * value, std::ostream * json_stream)
{
	json_stream->put ('"');

	for (char c : *value)
	{
		switch (c)
		{
		case '"':
			json_stream->put ('\\');
			json_stream->put ('"');
			continue;
		case '\\':
			json_stream->put ('\\');
			json_stream->put ('\\');
			continue;
		case '\x08':
			json_stream->put ('\\');
			json_stream->put ('b');
			continue;
		case '\x09':
			json_stream->put ('\\');
			json_stream->put ('t');
			continue;
		case '\x0A':
			json_stream->put ('\\');
			json_stream->put ('n');
			continue;
		case '\x0C':
			json_stream->put ('\\');
			json_stream->put ('f');
			continue;
		case '\x0D':
			json_stream->put ('\\');
			json_stream->put ('r');
			continue;
		default:
			if (c < '\x20')
			{
				Error::T ret;
				if ((ret = encode (c, json_stream))) return ret;
				continue;
			}
			json_stream->put (c);
			continue;
		}
	}

	json_stream->put ('"');
	return Error::NONE;
}
