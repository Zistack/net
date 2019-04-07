template <typename InputStream>
std::string
getVersion (InputStream && input_stream)
{
	std::string version;

	std::string token;

	if
	(
		(token = getToken (std::forward <InputStream> (input_stream))) != "HTTP"
	)
	{
		throw Failure::SyntaxError::T ("Invalid token: " + token + "\n");
	}

	IO::Util::expect (std::forward <InputStream> (input_stream), '/');

	uint64_t major = IO::Rule::getUInt
	(
		std::forward <InputStream> (input_stream)
	);

	IO::Util::expect (std::forward <InputStream> (input_stream), '.');

	uint64_t minor = IO::Rule::getUInt
	(
		std::forward <InputStream> (input_stream)
	);

	return "HTTP/" + std::to_string (major) + "." + std::to_string (minor);
}
