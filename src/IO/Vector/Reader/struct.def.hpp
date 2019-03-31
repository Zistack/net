struct T
{
	T (const std::vector <uint8_t> & vector);

	char
	get ();

	char
	peek ();

	bool
	eof () const;

	~T () = default;

	private:
	const std::vector <uint8_t> & vector;
	std::vector <uint8_t>::size_type pointer;

	static_assert (TypeTraits::IsInputStream::T <T>::value);
};
