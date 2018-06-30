std::string
getPChars (IO::Interface::PeekableInputStream::T <char> * input_stream)
{
	const std::string message_prefix = "HTTP::URI::Rule::getPChars\n";

	try
	{
		std::string pchars;

		while (true)
		{
			char c = input_stream -> peek ();

			if (Class::pchar (c)) pchars.push_back (input_stream -> get ());
			else if (c == '%') pchars.push_back (getEscape (input_stream));
			else return pchars;
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
