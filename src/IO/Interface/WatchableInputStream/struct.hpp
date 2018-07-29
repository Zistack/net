struct T : Watchable::T, InputStream::T
{
	virtual Watchable::Events::T
	events () const override = 0;

	virtual int
	fileDescriptor () const override = 0;

	virtual char
	get () override = 0;
};
