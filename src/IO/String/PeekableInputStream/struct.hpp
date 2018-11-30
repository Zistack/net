struct T : Interface::PeekableInputStream::T
{
	T (const std::string & string, std::string::size_type & pointer);

	char
	get () override;

	char
	peek () override;

	~T () = default;

	private:
	const std::string & string;
	std::string::size_type & pointer;
};
