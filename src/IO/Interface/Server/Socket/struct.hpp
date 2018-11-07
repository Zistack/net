struct T : Watchable::T
{
	virtual std::unique_ptr<Interface::Socket::T>
	accept () = 0;

	virtual Watchable::Events::T
	events () const override = 0;

	virtual int
	fileDescriptor () const override = 0;

	virtual ~T () = default;
};
