struct T : Watchable::T
{
	virtual size_t
	read (char * buffer, size_t count) = 0;

	virtual Watchable::Events::T
	events () const override = 0;

	virtual int
	fileDescriptor () const override = 0;
};
