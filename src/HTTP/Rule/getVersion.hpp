std::string
getVersion (IO::Interface::PeekableInputStream::T & input_stream)
{
	std::string version;

	std::string token;

	if ((token = getToken (input_stream)) != "HTTP")
	{
		throw Failure::SyntaxError::T ("Invalid token: " + token + "\n");
	}

	IO::Util::expect (input_stream, '/');

	uint64_t major = IO::Rule::getNum (input_stream);

	IO::Util::expect (input_stream, '.');

	uint64_t minor = IO::Rule::getNum (input_stream);

	return "HTTP/" + std::to_string (major) + "." + std::to_string (minor);
}
