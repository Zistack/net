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

	Data::T & m_vector;
	Size::T m_pointer;
};

static_assert (IsOutputStream::T <T>::value);
