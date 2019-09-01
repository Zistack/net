template <typename InputStream>
struct T
{
	T (InputStream input_stream, std::array <uint8_t, 4> masking_key);

	char
	get ();

	~T () = default;

private:

	InputStream input_stream;

	std::array <uint8_t, 4> masking_key;

	unsigned int masking_key_idx;

	static_assert (IO::TypeTraits::IsInputStream::T <T>::value);
};

template <typename InputStream>
T (InputStream && input_stream) -> T <InputStream>;