template <typename InputStream, typename OutputStream>
void
T::recode (InputStream && input_stream, OutputStream && output_stream)
{
	size_t count = this -> m_count;

	while (count > 0)
	{
		const size_t BUF_SIZE = 4096;

		char buffer [BUF_SIZE];

		size_t bytes = count > BUF_SIZE ? BUF_SIZE : count;

		size_t i;
		for (i = 0; i < bytes; ++i)
		{
			buffer [i] = input_stream . get ();
		}

		output_stream . write (buffer, bytes);

		count -= bytes;
	}
}
