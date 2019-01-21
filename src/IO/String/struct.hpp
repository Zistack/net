struct T : Interface::ByteBlock::T
{
	T ();

	T (const std::string & string);

	T (std::string && string);

	operator std::string ();

	operator const std::string & ();

	void
	reset () override;

	off_t
	size () override;

	PeekableInputStream::T &
	peekableInputStream () override;

	PeekableInputStream::T &
	inputStream () override;

	OutputStream::T &
	outputStream () override;

	~T () override = default;

	private:
	std::string string;
	std::string::size_type pointer;

	PeekableInputStream::T peekable_input_stream;
	OutputStream::T output_stream;
};
