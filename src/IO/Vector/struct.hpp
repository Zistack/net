struct T : Interface::ByteBlock::T
{
	T ();

	T (const std::vector<uint8_t> & vector);

	T (std::vector<uint8_t> && vector);

	operator std::vector<uint8_t> ();

	operator const std::vector<uint8_t> & ();

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
	std::vector<uint8_t> vector;
	std::vector<uint8_t>::size_type pointer;

	PeekableInputStream::T peekable_input_stream;
	OutputStream::T output_stream;
};
