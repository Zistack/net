struct T
{
	template <typename InputStream>
	T (InputStream && input_stream);

	T (const std::string & name, const NullableString::T & version = nullptr);

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream);

	~T () = default;

	std::string name;
	NullableString::T version;
};
