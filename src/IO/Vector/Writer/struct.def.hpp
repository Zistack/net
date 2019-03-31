struct T
{
	T (std::vector <uint8_t> & vector);

	void
	put (char c);

	void
	write (const char * buffer, size_t count);

	void
	print (const std::string & string);

	~T () = default;

	private:
	std::vector <uint8_t> & vector;
	std::vector <uint8_t>::size_type pointer;

	static_assert (TypeTraits::IsOutputStream::T <T>::value);
};
