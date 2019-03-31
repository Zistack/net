template <typename PeekableInputStream>
bool
test (PeekableInputStream && input_stream, char e)
{
	char c;

	try
	{
		c = input_stream . peek ();
	}
	catch (Failure::EndOfResource::T)
	{
		return false;
	}

	return c == e;
}

template <typename PeekableInputStream, typename Predicate, typename>
bool
test (PeekableInputStream && input_stream, Predicate && classPredicate)
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
