template <typename CharType>
struct T : virtual Watchable::T, virtual OutputStream::T <CharType>
{
	virtual uint32_t events () const override = 0;
	virtual int fd () const override = 0;

	virtual void put (CharType c) override = 0;
};
