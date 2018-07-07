void
skipWhitespace (IO::Interface::PeekableInputStream::T * input_stream)
{
	while (IO::Util::test (input_stream, Class::whitespace))
	{
		input_stream->get ();
	}
}
