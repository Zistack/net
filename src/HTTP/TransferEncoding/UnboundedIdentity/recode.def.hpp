template <typename InputStream, typename OutputStream>
void
T::recode (InputStream && input_stream, OutputStream && output_stream)
{
	const size_t BUF_SIZE = 1024;

	char buffer [BUF_SIZE];

	size_t bytes = BUF_SIZE;

	while (bytes == BUF_SIZE)
	{
		try
		{
			for (bytes = 0; bytes < BUF_SIZE; ++ bytes)
			{
				buffer [bytes] = input_stream . get ();
			}
		}
		catch (Failure::EndOfResource::T)
		{
		}

		if (bytes) output_stream . write (buffer, bytes);
	}
}
