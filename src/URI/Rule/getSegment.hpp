std::string
getSegment (IO::Interface::PeekableInputStream::T & input_stream)
{
	return getClassDecode (input_stream, Class::pchar);
}
