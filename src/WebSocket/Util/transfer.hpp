void
transfer (IO::Interface::InputStream::T & input_stream,
    uint64_t count,
    IO::Interface::OutputStream::T & output_stream)
{
	uint64_t i;
	for (i = 0; i < count; ++i)
	{
		output_stream.put (input_stream.get ());
	}
}
