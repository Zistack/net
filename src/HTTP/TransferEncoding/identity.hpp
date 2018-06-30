void
identity
(
	IO::Interface::InputStream::T <char> * input_stream,
	IO::OutputStream::T * output_stream,
	uint64_t size
)
{
	do
	{
		output_stream -> put (input_stream -> get ());
		-- size;
	}
	while (size != 0);
}
