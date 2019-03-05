template <typename InputStream, typename Predicate>
std::string
getClass (InputStream && input_stream, Predicate && classPredicate)
{
	std::string string;

	while (
	    Util::test (std::forward<InputStream> (input_stream), classPredicate))
	{
		string.push_back (input_stream.get ());
	}

	return string;
}
