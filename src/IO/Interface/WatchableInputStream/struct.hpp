template <typename CharType>
struct T : virtual Watchable::T, virtual InputStream::T <CharType>
{
	virtual uint32_t events () const override = 0;
	virtual int fd () const override = 0;

	virtual CharType get () override = 0;
};
