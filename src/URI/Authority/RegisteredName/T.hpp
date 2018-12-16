T::T (IO::Interface::PeekableInputStream::T & input_stream)
{
	this->registered_name = Rule::getClassDecode (input_stream, Class::rnchar);
}

T::T (const std::string & registered_name) : registered_name (registered_name)
{
}
