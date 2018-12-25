void
T::recode (IO::Interface::InputStream::T & input_stream,
    IO::Interface::OutputStream::T & output_stream)
{
	char buffer[this->chunk_size];

	size_t i;

	while (true)
	{
		try
		{
			for (i = 0; i < this->chunk_size; ++i)
			{
				buffer[i] = input_stream.get ();
			}
		}
		catch (IO::EOF::T)
		{
		}

		IO::Rule::putHex (i, output_stream);

		// We don't produce extensions.
		output_stream.print ("\r\n");

		if (!i) break;

		output_stream.write (buffer, i);
		output_stream.print ("\r\n");
	}

	// We don't produce trailers.
	output_stream.print ("\r\n");
}
