T::T (IO::InputStream::T * input_stream)
{
	const std::string message_prefix = "HTTP::URI::T\n";

	try
	{
		std::string scheme = Rule::getScheme (input_stream);

		if (! (scheme == "http" || scheme == "https"))
		{
			throw IO::EncodingError ("Only 'http' or 'https' are valid schemes");
		}

		host = Rule::getHost (input_stream);

		if (IO::Util::test (input_stream, ':'))
		{
			input_stream -> get ();
			port = Rule::getNum (input_stream);
		}
		else
		{
			if (scheme == "http") port = 80;
			if (scheme == "https") port = 443;
		}

		if (IO::Util::test (input_stream, '?'))
		{
			throw IO::EncodingError
			(
				IO::Message::unexpectedCharacter ('?', '/')
			);
		}

		absolute_path = Rule::getAbsolutePath (input_stream);

		if (IO::Util::test (input_stream, '?'))
		{
			input_stream -> get ();
			query = Rule::getQuery (input_stream);
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}

T::T (std::string scheme,
	std::string host,
	std::string port,
	Path::T absolute_path,
	std::string query) :
	scheme (scheme),
	host (host),
	port (port),
	absolute_path (absolute_path),
	query (query)
{
}
