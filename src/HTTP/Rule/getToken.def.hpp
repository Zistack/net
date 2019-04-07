template <typename InputStream>
std::string
getToken (InputStream && input_stream)
{
	std::string token = IO::Rule::getClass
	(
		std::forward <InputStream> (input_stream),
		Class::token
	);

	if (token . empty ()) throw Failure::SyntaxError::T ("Expected token\n");

	return token;
}
