struct T : Interface::PeekableInputStream::T, Interface::OutputStream::T
{
	T (std::string & string);

	char
	get () override;

	char
	peek () override;

	void
	put (char c) override;

	void
	write (const char * buffer, size_t count) override;

	void
	reset ();
	off_t
	size ();

	~T () = default;

	std::string & string;
	std::string::size_type pointer;
};
