bool
test (IO::Interface::PeekableInputStream::T * input_stream, char e)
{
	char c;

	try
	{
		c = input_stream->peek ();
	}
	catch (EOF::T e)
	{
		return false;
	}

	return c == e;
}

bool
test (IO::Interface::PeekableInputStream::T * input_stream,
    std::function<bool(char c)> classPredicate)
{
	char c;

	try
	{
		c = input_stream->peek ();
	}
	catch (EOF::T e)
	{
		return false;
	}

	return classPredicate (c);
}
