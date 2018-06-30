template <typename CharType>
void
expect (Interface::InputStream::T <CharType> * input_stream, CharType e)
{
	CharType c = input_stream -> get ();

	if (c != e)
	{
		throw EncodingError::T (Message::unexpectedcharacter (c, e));
	}
}

template <typename CharType>
CharType
expect (Interface::InputStream::T <CharType> * input_stream,
	std::function <bool (CharType c)> classPredicate)
{
	CharType c = input_stream -> get ();

	if (classPredicate (c)) return c;

	throw EncodingError::T (Message::unexpectedCharacter (c));
}

template <typename CharType>
void
expect (Interface::InputStream::T <CharType> * input_stream,
	std::basic_string <CharType> expected)
{
	for (CharType e : expected) expect (input_stream, e);
}
