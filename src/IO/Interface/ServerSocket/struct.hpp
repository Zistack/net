struct T : Watchable::T
{
	virtual ClientSocket::T *
	accept () = 0;

	virtual Watchable::Events::T
	events () const override = 0;

	virtual int
	fileDescriptor () const override = 0;

	virtual ~T () = default;
};
