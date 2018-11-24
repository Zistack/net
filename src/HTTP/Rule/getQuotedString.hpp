std::string
getQuotedString (IO::Interface::PeekableInputStream::T & input_stream)
{
	const std::string message_prefix = "HTTP::Rule::getQuotedString\n";

	try
	{
		std::string quoted_string;

		IO::Util::expect (input_stream, '"');

		while (true)
		{
			char c = input_stream.peek ();

			if (c == '"')
			{
				input_stream.get ();
				return quoted_string;
			};

			if (c == '\\')
			{
				input_stream.get ();
				quoted_string.push_back (
				    IO::Util::expect (input_stream, Class::text));
			}

			quoted_string.push_back (
			    IO::Util::expect (input_stream, Class::text));
		}
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
