std::string
getToken (IO::Interface::PeekableInputStream::T & input_stream)
{
	std::string token = IO::Rule::getClass (input_stream, Class::token);

	if (token.empty ()) throw Failure::SyntaxError::T ("Expected token\n");

	return token;
}
