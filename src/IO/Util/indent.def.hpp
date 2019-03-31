template <typename OutputStream>
void
indent (OutputStream && output_stream, size_t indentation)
{
	for (; indentation > 0; --indentation) output_stream . put ('\t');
}
