struct T : Watchable::T, OutputStream::T
{
	virtual Watchable::Events::T
	events () const override = 0;

	virtual int
	fileDescriptor () const override = 0;

	virtual void
	put (char c) override = 0;

	virtual void
	write (const char * buffer, size_t count) override = 0;
};
