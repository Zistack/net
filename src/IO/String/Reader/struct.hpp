struct T : Interface::PeekableInputStream::T
{
	T (const std::string & string);

	char
	get () override;

	char
	peek () override;

	bool
	eof () const;

	~T () = default;

	private:
	const std::string & string;
	std::string::size_type pointer;
};
