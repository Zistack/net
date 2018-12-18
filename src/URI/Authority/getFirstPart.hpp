std::string
T::getFirstPart (IO::Interface::PeekableInputStream::T & input_stream)
{
	return IO::Rule::getNotClass (input_stream, '@');
}
