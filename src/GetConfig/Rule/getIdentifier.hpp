std::string
getIdentifier (IO::Interface::PeekableInputStream::T & input_stream)
{
	return IO::Rule::getClass (input_stream, Class::identifier);
}
