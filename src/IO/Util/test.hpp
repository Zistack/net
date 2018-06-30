template <typename CharType>
bool
test (IO::Interface::PeekableInputStream <CharType> * input_stream, CharType e)
{
	CharType c;

	try c = input_stream -> peek ();
	catch (EOF::T e) return false;

	return c == e;
}

template <typename CharType>
bool
test (IO::Interface::PeekableInputStream <CharType> * input_stream,
	std::function <bool (CharType c)> classPredicate)
{
	CharType c;

	try c = input_stream -> peek ();
	catch (EOF::T e) return false;

	return classPredicate (c);
}
