struct T : Interface::PeekableInputStream::T
{
	T (Interface::InputStream::T * input_stream);

	char
	get () override;

	char
	peek () override;

	~T () = default;

	Interface::InputStream::T * input_stream;

	char peek_char;
	bool peekable;
};
