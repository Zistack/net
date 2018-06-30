std::string
getDomainLabel (IO::Interface::PeekableInputStream::T <char> * input_stream)
{
	const std::string message_prefix = "HTTP::URI::Rule::getDomainLabel";

	try
	{
		std::string domain_label;

		domain_label.push_back (IO::Util::expect (input_stream, Class::alphanum));

		while (true)
		{
			c = input_stream -> peek ();

			if (c == '-')
			{
				do domain_label.push_back ((c = input_stream.get ()));
				while (c == '-');

				if (! Class::alphanum (c)) // Bad things.

				continue;
			}

			if (! Class::alphanum (c)) return domain_label;

			domain_label.push_back (input_stream -> get ());
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
