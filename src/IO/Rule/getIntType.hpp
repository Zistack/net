template <class IntType>
IntType
getIntType (IO::Interface::InputStream::T & input_stream)
{
	IntType integer = 0;

	int i;
	for (i = sizeof (IntType) - 1; i >= 0; --i)
	{
		integer |= (input_stream.get () << (i * 8));
	}

	return integer;
}
