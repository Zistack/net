template <typename IntType, typename OutputStream>
void
putIntType (IntType integer, OutputStream && output_stream)
{
	char buffer [sizeof (IntType)];

	int i;
	for (i = 0; i < sizeof (IntType); ++i)
	{
		buffer [i] = (char) ((integer >> (i * 8)) & 0xFF);
	}

	output_stream . write (buffer, sizeof (IntType));
}
