struct T
{
	template <typename InputStream>
	T (InputStream && input_stream);

	T (const std::string & string);

	operator const std::string & () const;

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream, size_t indentation = 0) const;

	~T () = default;

	std::string value;
};
