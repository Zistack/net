T::T (IO::Interface::PeekableInputStream::T & input_stream)
{
	init (input_stream);
}

T::T (std::string number)
{
	IO::String::T string_stream (number);

	init (string_stream);

	if (!string_stream.eof ())
	{
		throw Failure::Error::T ("JSON::Number::T\n" +
		    IO::Message::unexpectedCharacter (string_stream.peek ()));
	}
}
