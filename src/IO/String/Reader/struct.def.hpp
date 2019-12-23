struct T
{
	T (const Data::T & string);

	T (const Data::T & string, Size::T initial_position);

	char
	get ();

	char
	peek ();

	bool
	eof () const;

	~T () = default;

private:

	const Data::T & m_string;
	Size::T m_pointer;
};

static_assert (IsInputStream::T <T>::value);
