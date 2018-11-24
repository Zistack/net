std::string
getVersion (IO::Interface::PeekableInputStream::T & input_stream)
{
	const std::string message_prefix = "HTTP::Rule::getVersion\n";

	try
	{
		std::string version;

		std::string token;

		if ((token = getToken (input_stream)) != "HTTP")
		{
			throw Failure::Error::T ("Invalid token: " + token + "\n");
		}

		IO::Util::expect (input_stream, '/');

		uint64_t major = getNum (input_stream);

		IO::Util::expect (input_stream, '.');

		uint64_t minor = getNum (input_stream);

		return "HTTP/" + std::to_string (major) + "." + std::to_string (minor);
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
