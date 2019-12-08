template <typename InputStream>
struct T
{
	T (InputStream input_stream, Key::T masking_key);

	char
	get ();

	char
	peek ();

	bool
	eof ();

	~T () = default;

private:

	InputStream m_input_stream;

	Key::T m_masking_key;

	unsigned int m_masking_key_index;

};

template <typename InputStream>
T (InputStream && input_stream, Key::T masking_key) -> T <InputStream>;

static_assert
(
	IO::TypeTraits::IsInputStream::T <T <IO::TypeTraits::InputStream::T>>::value
);
