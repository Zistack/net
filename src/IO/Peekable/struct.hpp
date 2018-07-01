struct T : Interface::PeekableInputStream::T
{
	T (Interface::InputStream::T * input_stream);

	char
	get () override;
	char
	peek () override;

	~T ();

	char peek_char;
	bool peekable;
	Interface::InputStream::T * input_stream;
};
