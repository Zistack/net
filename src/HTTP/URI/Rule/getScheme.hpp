std::string
getScheme (IO::Interface::PeekableInputStream::T <char> * input_stream)
{
	const std::string message_prefix = "HTTP::URI::Rule::getScheme\n";

	try
	{
		std::string scheme;

		scheme.push_back (Util::expect (input_stream, Class::alpha));

		while (true)
		{
			char c = input_stream -> peek ();

			if (Class::schar (c)) scheme.push_back (input_stream -> get ());
			else return scheme;
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
