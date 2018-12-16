template <class Predicate>
std::string
getClassDecode (IO::Interface::PeekableInputStream::T & input_stream,
    Predicate && classPredicate)
{
	std::string string;

	while (true)
	{
		if (IO::Util::test (input_stream, '%'))
		{
			string.push_back (getEncoded (input_stream));
		}
		else if (IO::Util::test (input_stream, classPredicate))
		{
			string.push_back (input_stream.get ());
		}
		else
		{
			break;
		}
	}

	return string;
}
