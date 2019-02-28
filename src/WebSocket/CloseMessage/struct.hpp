struct T
{
	T (Masking::InputStream::T & input_stream, uint64_t length);

	T (uint16_t status_code = 1005, const NullableString::T & reason = nullptr);

	uint64_t
	length () const;

	void
	writeTo (Masking::OutputStream::T & output_stream) const;

	~T () = default;

	uint16_t status_code;
	NullableString::T reason;
};
