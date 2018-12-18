template <class Predicate>
std::string
getNotClass (Interface::PeekableInputStream::T & input_stream,
    Predicate && classPredicate)
{
	std::string string;

	while (
	    !Util::test (input_stream, std::forward<Predicate> (classPredicate)) &&
	    !input_stream.eof ())
	{
		string.push_back (input_stream.get ());
	}

	return string;
}
