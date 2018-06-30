std::string
getQuotedString (
	IO::Interface::PeekableInputStream::T <char> * filtered_input_stream
)
{
	const std::string message_prefix = "HTTP::Rule::getQuotedString\n";

	try
	{
		Util::skipWhitespace (filtered_input_stream);

		std::string quoted_string;

		IO::Util::expect (filtered_input_stream, '"');

		while (true)
		{
			char c = filtered_input_stream -> peek ();

			if (c == '"') break;

			IO::Util::expect (filtered_input_stream, Class::text);

			if (c == '\\')
			{
				c = IO::Util::expect (filtered_input_stream, Class::text);
			}

			quoted_string.push_back (c);
		}

		return quoted_string;
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
