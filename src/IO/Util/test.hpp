bool
test (Interface::PeekableInputStream::T & input_stream, char e)
{
	char c;

	try
	{
		c = input_stream.peek ();
	}
	catch (Failure::EndOfResource::T)
	{
		return false;
	}

	return c == e;
}

template <class Predicate,
    typename
#ifndef IO_Util_test_hpp_2
#define IO_Util_test_hpp_2
    = typename std::enable_if<
        std::is_invocable_r<bool, Predicate, char>::value>::type
#endif /* IO_Util_test_hpp_2 */
    >
bool
test (Interface::PeekableInputStream::T & input_stream,
    Predicate && classPredicate)
{
	char c;

	try
	{
		c = input_stream.peek ();
	}
	catch (Failure::EndOfResource::T)
	{
		return false;
	}

	return classPredicate (c);
}
