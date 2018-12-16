void
T::recode (IO::Interface::InputStream::T & blocking_input_stream,
    IO::Interface::OutputStream::T & output_stream)
{
	IO::PeekableInputStream::T input_stream (blocking_input_stream);

	while (true)
	{
		uint64_t chunk_size = IO::Rule::getHex (input_stream);

		while (IO::Util::test (input_stream, ';'))
		{
			input_stream.get ();
			// We discard extensions, because we don't understand any.
			Rule::getChunkExtension (input_stream);
		}

		IO::Util::expect (input_stream, "\r\n");

		if (!chunk_size) break;

		BoundedIdentity::T chunk_transfer (chunk_size);
		chunk_transfer.recode (input_stream, output_stream);

		IO::Util::expect (input_stream, "\r\n");
	}

	// We discard trailers, because we don't understand any.
	HeaderMap::T trailers (input_stream);
}
