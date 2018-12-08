void
T::filter (
    IO::Interface::InputStream::T & input_stream,
    IO::Interface::OutputStream::T & output_stream,
{
	const size_t BUF_SIZE = 1024;

	char buffer[BUF_SIZE];

	size_t bytes = BUF_SIZE;

	while (bytes == BUF_SIZE)
	{
		try
		{
			for (bytes = 0; bytes < BUF_SIZE; ++bytes)
			{
				buffer[bytes] = input_stream.get ();
			}
		}
		catch (IO::EOF::T)
		{
		}

		if (bytes_read) output_stream->write (buffer, bytes_read);
	}
}
