template <typename OutputStream>
struct T
{
	T (OutputStream output_stream, Key::T masking_key);

	void
	put (char c);

	void
	write (const char * buffer, size_t count);

	void
	print (const std::string & string);

	~T () = default;

private:

	OutputStream m_output_stream;

	Key::T m_masking_key;

	unsigned int m_masking_key_index;
};

template <typename OutputStream>
T (OutputStream && output_stream, Key::T masking_key) ->
	T <OutputStream>;

static_assert (IO::IsOutputStream::T <T <IO::DummyOutputStream::T>>::value);
