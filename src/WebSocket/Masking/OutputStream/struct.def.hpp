template <typename OutputStream>
struct T
{
	T (OutputStream output_stream, std::array <uint8_t, 4> masking_key);

	void
	put (char c);

	void
	write (const char * buffer, size_t count);

	void
	print (const std::string & string);

	~T () = default;

private:

	OutputStream output_stream;

	std::array <uint8_t, 4> masking_key;

	unsigned int masking_key_index;

	static_assert (IO::TypeTraits::IsOutputStream::T <T>::value);
};

template <typename OutputStream>
T (OutputStream && output_stream, std::array <uint8_t, 4> masking_key) ->
	T <OutputStream>;
