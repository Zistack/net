template <typename CharType>
struct T : Interface::PeekableInputStream::T <CharType>
{
	T (Interface::InputStream::T <CharType> * input_stream);

	CharType get () override;
	CharType peek () override;

	~T ();

	CharType peek_char;
	bool peekable;
	Interface::InputStream::T <CharType> * input_stream;
};
