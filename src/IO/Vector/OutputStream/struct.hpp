struct T : Interface::OutputStream::T
{
	T (std::vector<uint8_t> & vector,
	    std::vector<uint8_t>::size_type & pointer);

	void
	put (char c) override;

	void
	write (const char * buffer, size_t count) override;

	private:
	std::vector<uint8_t> & vector;
	std::vector<uint8_t>::size_type & pointer;
};
