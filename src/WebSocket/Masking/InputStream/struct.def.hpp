template <typename InputStream>
struct T
{
	T (InputStream input_stream, Key::T masking_key);

	char
	get ();

	~T () = default;

private:

	InputStream m_input_stream;

	Key::T m_masking_key;

	unsigned int m_masking_key_idx;

	static_assert (IO::TypeTraits::IsInputStream::T <T>::value);
};

template <typename InputStream>
T (InputStream && input_stream, Key::T masking_key) -> T <InputStream>;
