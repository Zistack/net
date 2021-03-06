struct T
{
	using Value = std::chrono::nanoseconds;

	template <typename InputStream>
	static Value
	readFrom (InputStream && input_stream);

	template <typename OutputStream>
	static void
	writeTo
	(
		const Value & value,
		OutputStream && output_stream,
		size_t indentation
	);
};
