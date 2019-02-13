void
skipWhitespace (Interface::PeekableInputStream::T & input_stream)
{
	while (test (input_stream, Class::whitespace)) input_stream.get ();
}
