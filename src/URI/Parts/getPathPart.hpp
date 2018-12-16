std::string
T::getPathPart (IO::Interface::PeekableInputStream::T & input_stream)
{
	return IO::Rule::getNotClass (input_stream, Class::thirdDelimiter);
}
