template <typename CharType>
struct T : Interface::PeekableInputStream::T <CharType>, Interface::OutputStream::T <CharType>
{
	T (std::basic_string <CharType> * string);

	CharType get () override;
	CharType peek () override;

	void put (CharType c) override;

	void reset ();
	off_t size ();

	~T () = default;

	std::basic_string <CharType> * string;
	std::string::size_type pointer;
};
