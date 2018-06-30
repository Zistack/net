uint64_t
getNum (IO::Interface::PeekableInputStream::T <char> * input_stream)
{
	const std::string message_prefix = "HTTP::URI::Rule::getNum\n";

	try
	{
		std::string num;

		char c;

		while (IO::Util::test (input_stream, Class::digit))
		{
			num.push_back (input_stream -> get ());
		}

		try uint64_t ret = std::stoull (num);
		catch (std::out_of_range e)
		{
			throw IO::EncodingError ("Number is too large to fit into a 64 bit integer");
		}

		return ret;
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
