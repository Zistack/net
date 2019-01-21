struct T : Interface::PeekableInputStream::T
{
	T (const std::vector<uint8_t> & vector,
	    std::vector<uint8_t>::size_type & pointer);

	char
	get () override;

	char
	peek () override;

	~T () = default;

	private:
	const std::vector<uint8_t> & vector;
	std::vector<uint8_t>::size_type & pointer;
};
