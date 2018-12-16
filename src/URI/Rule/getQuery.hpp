std::string
getQuery (IO::Interface::PeekableInputStream::T & input_stream)
{
	return getClassDecode (input_stream, Class::qchar);
}
