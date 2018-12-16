std::string
getScheme (IO::Interface::PeekableInputStream::T & input_stream)
{
	std::string scheme;

	scheme.push_back (IO::Util::expect (input_stream, IO::Class::alpha));

	while (IO::Util::test (input_stream, Class::schar))
	{
		scheme.push_back (input_stream.get ());
	}

	return scheme;
}
