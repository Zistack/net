struct T
{
	T () = default;

	T (const std::string & string);

	std::string::size_type
	size () const;

	Reader::T
	reader () const;

	Writer::T
	writer ();

	~T () = default;

private:

	std::string string;
};