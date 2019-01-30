struct T : Watchable::T, InputStream::T, Failure::Cancellable::T
{
	virtual Watchable::Events::T
	events () const override = 0;

	virtual int
	fileDescriptor () const override = 0;

	virtual char
	get () override = 0;

	virtual void
	cancel () override = 0;
};
