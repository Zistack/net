void
skipWhitespace (IO::Interface::PeekableInputStream::T <char> * input_stream)
{
	while (IO::Util::test (input_stream, Class::whitespace)) input_stream -> get ();
}
