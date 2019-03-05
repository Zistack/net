struct T
{
	T (const std::string & string);

	char
	get ();

	char
	peek ();

	bool
	eof () const;

	~T () = default;

	private:
	const std::string & string;
	std::string::size_type pointer;
};
