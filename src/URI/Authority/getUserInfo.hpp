std::string
T::getUserInfo (IO::Interface::PeekableInputStream::T & input_stream)
{
	return Rule::getClassDecode (input_stream, Class::uichar);
}
