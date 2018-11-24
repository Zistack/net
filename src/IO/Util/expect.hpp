void
expect (Interface::InputStream::T & input_stream, char e)
{
	char c = input_stream.get ();

	if (c != e)
	{
		throw Failure::Error::T (Message::unexpectedCharacter (c, e));
	}
}

template <class Predicate,
    typename
#ifndef IO_Util_expect_hpp_2
#define IO_Util_expect_hpp_2
    = typename std::enable_if<
        std::is_invocable_r<bool, Predicate, char>::value>::type
#endif
    >
char
expect (Interface::InputStream::T & input_stream, Predicate && classPredicate)
{
	char c = input_stream.get ();

	if (classPredicate (c)) return c;

	throw Failure::Error::T (Message::unexpectedCharacter (c));
}

void
expect (Interface::InputStream::T & input_stream, std::string expected)
{
	for (char e : expected) expect (input_stream, e);
}
