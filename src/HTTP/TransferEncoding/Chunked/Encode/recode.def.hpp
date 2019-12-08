template <typename InputStream, typename OutputStream>
void
T::recode (InputStream && input_stream, OutputStream && output_stream) const
{
	char buffer [this -> m_chunk_size];

	size_t i;

	while (true)
	{
		try
		{
			for (i = 0; i < this -> m_chunk_size; ++ i)
			{
				buffer [i] = input_stream . get ();
			}
		}
		catch (Failure::EndOfResource::T)
		{
		}

		IO::Rule::putHex (i, std::forward <OutputStream> (output_stream));

		// We don't produce extensions.
		output_stream . print ("\r\n");

		if (! i) break;

		output_stream . write (buffer, i);
		output_stream . print ("\r\n");
	}

	// We don't produce trailers.
	output_stream . print ("\r\n");
}
