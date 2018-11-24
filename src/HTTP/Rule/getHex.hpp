uint64_t
getHex (IO::Interface::PeekableInputStream::T & input_stream)
{
	const std::string message_prefix = "HTTP::Rule::getHex\n";

	try
	{
		std::string hex;

		while (IO::Util::test (input_stream, Class::hex))
		{
			hex.push_back (input_stream.get ());
		}

		// What happens if hex is empty here?

		uint64_t ret;

		try
			ret = std::stoull (hex, NULL, 16);
		catch (std::out_of_range e)
		{
			throw Failure::Error::T (
			    "Failed to convert hex string to integer:\n" + e.what () +
			    "\n");
		}

		return ret;
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
