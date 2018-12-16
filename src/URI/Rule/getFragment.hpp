std::string
getFragment (IO::Interface::PeekableInputStream::T & input_stream)
{
	return getClassDecode (input_stream, Class::fchar);
}
