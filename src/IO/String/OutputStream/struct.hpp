struct T : Interface::OutputStream::T
{
	T (std::string & string, std::string::size_type & pointer);

	void
	put (char c) override;

	void
	write (const char * buffer, size_t count) override;

	private:
	std::string & string;
	std::string::size_type & pointer;
};
