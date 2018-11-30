struct T
{
	virtual void
	reset () = 0;

	virtual off_t
	size () = 0;

	virtual IO::Interface::NonblockingInputStream::T &
	inputStream () = 0;

	virtual IO::Interface::NonblockingOutputStream::T &
	outputStream () = 0;

	virtual ~T () = default;
};
