struct T
{
	virtual bool
	isBlocking () const;

	virtual IO::Interface::ByteBlock::T &
	asBlocking ();

	virtual bool
	isNonblocking () const;

	virtual IO::Interface::NonblockingByteBlock::T &
	asNonblocking ();

	virtual void
	reset () = 0;

	virtual off_t
	size () const = 0;

	virtual ~T () = default;
};
