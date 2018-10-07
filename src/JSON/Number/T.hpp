T::T (IO::Interface::PeekableInputStream::T * input_stream) :
    base (NULL),
    mantissa (NULL),
    exponent (NULL)
{
	init (input_stream);
}

T::T (std::string number) : base (NULL), mantissa (NULL), exponent (NULL)
{
	IO::String::T string_stream (&number);

	init (&string_stream);

	if (!string_stream.eof ())
	{
		throw Failure::Error::T ("JSON::Number::T\n" +
		    IO::Message::unexpectedCharacter (string_stream.peek ()));
	}
}
