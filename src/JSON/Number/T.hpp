T::T (IO::Interface::PeekableInputStream::T <char> * input_stream) :
	negative (false),
	base (NULL),
	mantissa (NULL),
	exponent_negative (false),
	exponent (NULL)
{
	init (input_stream);
}

T::T (std::string number) :
	negative (false),
	base (NULL),
	mantissa (NULL),
	exponent_negative (false),
	exponent (NULL)
{
	IO::String::T string_stream (number);

	init (& string_stream);

	if (! string_stream -> eof ())
	{
		throw Error::T ("Failed to parse number:\n" +
			Error::unexpectedCharacter (string_stream -> peek ()));
	}
}
