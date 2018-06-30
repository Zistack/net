std::string
getIPv4Address (IO::Interface::PeekableInputStream::T <char> * input_stream)
{
	const std::string message_prefix = "HTTP::URI::Rule::getIPv4Address\n";

	try
	{
		uint64_t first = getNum (input_stream);

		if (first > 255) throw IO::EncodingError ("IPv4 octet must be less than 256");

		IO::Util::expect (input_stream, '.');
		uint64_t second = getNum (input_stream);

		if (second > 255) throw IO::EncodingError ("IPv4 octet must be less than 256");

		IO::Util::expect (input_stream, '.');
		uint64_t third = getNum (input_stream);

		if (third > 255) throw IO::EncodingError ("IPv4 octet must be less than 256");

		IO::Util::expect (input_stream, '.');
		uint64_t fourth = getNum (input_stream);

		if (fourth > 255) throw IO::EncodingError ("IPv4 octet must be less than 256");

		return std::to_string (first) +
			"." +
			std::to_string (second) +
			"." +
			std::to_string (third) +
			"." +
			std::to_string (fourth);
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
