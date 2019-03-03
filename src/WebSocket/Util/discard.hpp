void
discard (IO::Interface::InputStream::T & input_stream, uint64_t count)
{
	uint64_t i;
	for (i = 0; i < count; ++i) input_stream.get ();
}
