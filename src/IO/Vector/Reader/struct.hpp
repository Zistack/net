struct T : Interface::PeekableInputStream::T
{
	T (const std::vector<uint8_t> & vector);

	char
	get () override;

	char
	peek () override;

	bool
	eof () const;

	~T () = default;

	private:
	const std::vector<uint8_t> & vector;
	std::vector<uint8_t>::size_type pointer;
};
