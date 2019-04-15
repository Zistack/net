template <typename InputStream, typename OutputStream>
void
transfer
(
	InputStream && input_stream,
	uint64_t count,
	OutputStream && output_stream
)
{
	uint64_t i;
	for (i = 0; i < count; ++ i)
	{
		output_stream . put (input_stream . get ());
	}
}
