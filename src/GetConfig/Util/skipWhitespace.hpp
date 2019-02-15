void
skipWhitespace (IO::Interface::PeekableInputStream::T & input_stream)
{
	while (true)
	{
		if (IO::Util::test (input_stream, IO::Class::whitespace))
		{
			input_stream.get ();
		}
		else if (IO::Util::test (input_stream, '#'))
		{
			while (!IO::Util::test (input_stream, '\n')) input_stream.get ();
		}
		else
			return;
	}
}
