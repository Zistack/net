template <typename InputStream, typename Predicate>
std::string
getClassDecode (InputStream && input_stream, Predicate && classPredicate)
{
	std::string string;

	while (true)
	{
		if (IO::Util::test (std::forward<InputStream> (input_stream), '%'))
		{
			string.push_back (
			    getEncoded (std::forward<InputStream> (input_stream)));
		}
		else if (IO::Util::test (
		             std::forward<InputStream> (input_stream), classPredicate))
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
