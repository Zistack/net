uint64_t
getHex (IO::Interface::PeekableInputStream::T <char> * filtered_input_stream)
{
	const std::string message_prefix = "HTTP::Rule::getHex\n";

	try
	{
		Util::skipWhitespace (filtered_input_stream);

		std::string hex;

		while (Class::hex (filtered_input_stream -> peek ()))
		{
			hex.push_back (filtered_input_stream -> get ());
		}

		uint64_t ret;

		try ret = std::stoull (hex, NULL, 16);
		catch (std::out_of_range e)
		{
			throw IO::EncodingError::T (
				"Failed to convert chunk size string to integer:\n" +
				e.what () + "\n"
			);
		}

		return ret;
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
