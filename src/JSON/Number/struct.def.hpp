struct T
{
	template <typename InputStream>
	T (InputStream && input_stream);

	T (const std::string & number_string);

	uint64_t
	toUInt () const;

	int64_t
	toInt () const;

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream, size_t indentation = 0) const;

	~T () = default;

private:

	template <typename InputStream>
	void
	init (InputStream && input_stream);

	std::string m_base;
	NullableString::T m_mantissa;
	NullableString::T m_exponent;
};
