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

	virtual ~T () = default;
};
