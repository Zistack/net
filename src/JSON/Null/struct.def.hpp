struct T
{
	T () = default;

	template <typename InputStream>
	T (InputStream && input_stream);

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream, size_t indentation = 0) const;

	~T () = default;
};
