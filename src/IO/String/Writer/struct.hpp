struct T : Interface::OutputStream::T
{
	T (std::string & string);

	void
	put (char c) override;

	void
	write (const char * buffer, size_t count) override;

	void
	print (const std::string & string);

	~T () = default;

	private:
	std::string & string;
	std::string::size_type pointer;
};
