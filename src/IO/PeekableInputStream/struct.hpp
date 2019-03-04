template <typename InputStream>
struct T : Interface::PeekableInputStream::T
{
	T (InputStream input_stream);

	char
	get () override;

	char
	peek () override;

	~T () = default;

	private:
	InputStream input_stream;

	char peek_char;
	bool peekable;
};
