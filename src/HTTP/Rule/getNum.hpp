uint64_t
getNum (IO::Interface::PeekableInputStream::T & input_stream)
{
	const std::string message_prefix = "HTTP::Rule::getNum\n";

	try
	{
		std::string num;

		while (IO::Util::test (input_stream, Class::digit))
		{
			num.push_back (input_stream.get ());
		}

		// What happens if num is empty here?

		uint64_t ret;

		try
			ret = std::stoull (num, NULL, 10);
		catch (std::out_of_range e)
		{
			throw Failure::Error::T (
			    "Failed to convert number string to integer:\n" +
			    e.what () + "\n");
		}

		return ret;
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
