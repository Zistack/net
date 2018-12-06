T::T (IO::Interface::PeekableInputStream::T & input_stream)
{
	init (input_stream);
}

T::T (std::string number)
{
	IO::String::T string (number);

	IO::String::PeekableInputStream::T & input_stream =
	    string.peekableInputStream ();

	init (input_stream);

	if (!input_stream.eof ())
	{
		throw Failure::Error::T ("JSON::Number::T\n" +
		    IO::Message::unexpectedCharacter (input_stream.peek ()));
	}
}
