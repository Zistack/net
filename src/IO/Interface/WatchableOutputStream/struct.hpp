struct T : virtual Watchable::T, virtual OutputStream::T
{
	virtual Watchable::Events::T
	events () const override = 0;

	virtual int
	fileDescriptor () const override = 0;

	virtual void
	put (char c) override = 0;
};
