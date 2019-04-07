struct T
{
	T () = default;

	T (const Options::T & options);

	template <typename InputStream, typename OutputStream>
	void
	recode (InputStream && input_stream, OutputStream && output_stream);

	~T () = default;
};
