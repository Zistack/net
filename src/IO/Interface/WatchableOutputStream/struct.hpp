struct T : virtual Watchable::T, virtual OutputStream::T
{
	virtual uint32_t
	events () const override = 0;
	virtual int
	fileDescriptor () const override = 0;

	virtual void
	put (char c) override = 0;
};
