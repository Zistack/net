struct T : virtual Watchable::T, virtual InputStream::T
{
	virtual uint32_t
	events () const override = 0;
	virtual int
	fileDescriptor () const override = 0;

	virtual char
	get () override = 0;
};
