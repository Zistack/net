struct T
{
	T (std::string & string);

	void
	put (char c);

	void
	write (const char * buffer, size_t count);

	void
	print (const std::string & string);

	~T () = default;

	private:
	std::string & string;
	std::string::size_type pointer;

	static_assert (TypeTraits::IsOutputStream::T<T>::value);
};
