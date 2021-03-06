template <typename InputStream>
void
expect (InputStream && input_stream, char e)
{
	char c = input_stream . get ();

	if (c != e)
	{
		throw Failure::SyntaxError::T (Message::unexpectedCharacter (c, e));
	}
}

template <typename InputStream, typename Predicate, typename>
char
expect (InputStream && input_stream, Predicate && classPredicate)
{
	char c = input_stream . get ();

	if (classPredicate (c)) return c;

	throw Failure::SyntaxError::T (Message::unexpectedCharacter (c));
}

template <typename InputStream>
void
expect (InputStream && input_stream, std::string expected)
{
	for (char e : expected)
	{
		expect (std::forward <InputStream> (input_stream), e);
	}
}
