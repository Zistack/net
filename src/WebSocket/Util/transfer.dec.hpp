template <typename InputStream, typename OutputStream>
void
transfer
(
	InputStream && input_stream,
	uint64_t count,
	OutputStream && output_stream
);

