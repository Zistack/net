struct T
{
	T () = default;

	T (const std::vector <uint8_t> & vector);

	std::vector <uint8_t>::size_type
	size () const;

	Reader::T
	reader () const;

	Writer::T
	writer ();

	~T () = default;

private:

	std::vector <uint8_t> vector;
};