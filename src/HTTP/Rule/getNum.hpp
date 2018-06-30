uint64_t
getNum (IO::Interface::PeekableInputStream::T <char> * filtered_input_stream)
{
	const std::string message_prefix = "HTTP::Rule::getNum\n";

	try
	{
		Util::skipWhitespace (filtered_input_stream);

		std::string num;

		while (Class::digit (filtered_input_stream -> peek ()))
		{
			num.push_back (filtered_input_stream -> get ());
		}

		uint64_t ret;

		try ret = std::stoull (num, NULL, 10);
		catch (std::out_of_range e)
		{
			throw Error::T (
				"Failed to convert chunk size string to integer:\n" +
				e.what () + "\n"
			);
		}

		return ret;
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
