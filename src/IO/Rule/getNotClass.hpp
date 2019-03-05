template <typename InputStream, typename Predicate>
std::string
getNotClass (InputStream && input_stream, Predicate && classPredicate)
{
	std::string string;

	while (!Util::test (std::forward<InputStream> (input_stream),
	           std::forward<Predicate> (classPredicate)) &&
	    !input_stream.eof ())
	{
		string.push_back (input_stream.get ());
	}

	return string;
}
