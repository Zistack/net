struct T
{
	T (Data::T & string);

	T (Data::T & string, Size::T initial_position);

	void
	put (char c);

	void
	write (const char * buffer, size_t count);

	void
	print (const std::string & string);

	~T () = default;

private:

	Data::T & m_string;
	Size::T m_pointer;
};

static_assert (IsOutputStream::T <T>::value);
