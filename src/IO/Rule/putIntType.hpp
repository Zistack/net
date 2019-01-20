template <class IntType>
void
putIntType (IntType integer, IO::Interface::OutputStream::T & output_stream)
{
	char buffer[sizeof (IntType)];

	int i;
	for (i = 0; i < sizeof (IntType); ++i)
	{
		buffer[i] = (integer >> (i * 8)) & 0xFF;
	}

	output_stream.write (buffer, sizeof (IntType));
}
