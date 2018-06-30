std::string
getHostName (IO::Interface::InputStream::T <char> * input_stream)
{
	const std::string message_prefix = "HTTP::URI::Rule::getHostName\n";

	try
	{
		std::string host_name;
		std::string domain_label;

		while (true)
		{
			domain_label = getDomainLabel (input_stream);

			host_name.append (domain_label);

			if (! IO::Util::test (input_stream, '.')) break;

			IO::Util::expect (input_stream, '.');

			if (! Class::alphanum (input_stream -> peek ())) break;

			host_name.push_back ('.');
		}

		if (! Class::alpha (domain_label.at (0)))
		{
			throw IO::EncodingError ("Hostname must start with alpha");
		}

		return host_name;
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
