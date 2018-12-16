template <class Predicate>
std::string
getClass (Interface::PeekableInputStream::T & input_stream,
    Predicate && classPredicate)
{
	std::string string;

	while (Util::test (input_stream, classPredicate))
	{
		string.push_back (input_stream.get ());
	}

	return string;
}
