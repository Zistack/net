template <typename CharType>
struct T : virtual InputStream::T <CharType>
{
	virtual CharType get () override = 0;
	virtual CharType peek () = 0;
	bool eof ();
};
