std::string
getVersion (
	IO::Interface::PeekableInputStream::T <char> * filtered_input_stream)
{
	const std::string message_prefix = "HTTP::Rule::getVersion\n";

	try
	{
		std::string version;

		std::string token;

		if ((token = getToken (filtered_input_stream)) != "HTTP")
		{
			throw IO::EncodingError::T ("Invalid token: " + token + "\n");
		}

		IO::Util::expect (filtered_input_stream, '/');

		uint64_t major = getNum (filtered_input_stream);

		IO::Util::expect (filtered_input_stream, '.');

		uint64_t minor = getNum (filtered_input_stream);

		return "HTTP/" + std::to_string (major) + "." + std::to_string (minor);
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
