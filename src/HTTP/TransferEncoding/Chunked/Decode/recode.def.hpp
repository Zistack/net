template <typename InputStream, typename OutputStream>
void
T::recode (InputStream && input_stream, OutputStream && output_stream) const
{
	while (true)
	{
		uint64_t chunk_size =
			IO::Rule::getHex (std::forward <InputStream> (input_stream));

		while (IO::Util::test (std::forward <InputStream> (input_stream), ';'))
		{
			input_stream . get ();
			// We discard extensions, because we don't understand any.
			Rule::getChunkExtension (std::forward <InputStream> (input_stream));
		}

		IO::Util::expect (std::forward <InputStream> (input_stream), "\r\n");

		if (! chunk_size) break;

		BoundedIdentity::T chunk_transfer (chunk_size);
		chunk_transfer . recode
		(
			std::forward <InputStream> (input_stream),
			std::forward <OutputStream> (output_stream)
		);

		IO::Util::expect (std::forward <InputStream> (input_stream), "\r\n");
	}

	// We discard trailers, because we don't understand any.
	HeaderMap::T trailers (std::forward <InputStream> (input_stream));
	IO::Util::expect (std::forward <InputStream> (input_stream), "\r\n");
}
