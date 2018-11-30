struct T
{
	virtual void
	reset () = 0;

	virtual off_t
	size () = 0;

	virtual IO::Interface::PeekableInputStream::T &
	peekableInputStream () = 0;

	virtual IO::Interface::InputStream::T &
	inputStream () = 0;

	virtual IO::Interface::OutputStream::T &
	outputStream () = 0;

	virtual ~T () = default;
};
