void
transfer (IO::Interface::InputStream::T & input_stream,
    uint64_t payload_length,
    std::array<uint8_t, 4> masking_key,
    IO::Interface::OutputStream::T & output_stream)
{
	uint64_t i;
	for (i = 0; i < payload_length; ++i)
	{
		// The only thing we might want to do is add a buffer so that we don't
		// make a million calls to write ();
		output_stream.put (masking_key[i % 4] ^ input_stream.get ());
	}
}
