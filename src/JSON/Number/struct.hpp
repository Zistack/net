struct T : Value::T
{
	T (IO::Interface::PeekableInputStream::T & input_stream);
	T (const std::string & number_string);

	uint64_t
	toUInt () const;

	int64_t
	toInt () const;

	void
	writeTo (IO::Interface::OutputStream::T & output_stream,
	    size_t indentation = 0) override;

	T &
	asNumber () override;

	~T () override = default;

	private:
	void
	init (IO::Interface::PeekableInputStream::T & input_stream);

	std::string base;
	NullableString::T mantissa;
	NullableString::T exponent;
};
