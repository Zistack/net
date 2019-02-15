std::string
getOp (IO::Interface::PeekableInputStream::T & input_stream)
{
	return IO::Rule::getClass (input_stream, IO::Class::alpha);
}
