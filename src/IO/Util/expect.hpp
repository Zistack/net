void
expect (Interface::InputStream::T * input_stream, char e)
{
	char c = input_stream->get ();

	if (c != e)
	{
		throw EncodingError::T (Message::unexpectedCharacter (c, e));
	}
}

char
expect (Interface::InputStream::T * input_stream,
    std::function<bool(char c)> classPredicate)
{
	char c = input_stream->get ();

	if (classPredicate (c)) return c;

	throw EncodingError::T (Message::unexpectedCharacter (c));
}

void
expect (Interface::InputStream::T * input_stream, std::string expected)
{
	for (char e : expected) expect (input_stream, e);
}
