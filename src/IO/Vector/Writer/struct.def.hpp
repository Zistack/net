struct T
{
	T (Data::T & vector);

	T (Data::T & vector, Size::T initial_position);

	void
	put (char c);

	void
	write (const char * buffer, size_t count);

	void
	print (const std::string & string);

	~T () = default;

	private:
	Data::T & vector;
	Size::T pointer;
};

static_assert (TypeTraits::IsOutputStream::T <T>::value);
