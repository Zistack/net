struct T
{
	T (const Data::T & vector);

	T (const Data::T & vector, Size::T initial_position);

	char
	get ();

	char
	peek ();

	bool
	eof () const;

	~T () = default;

private:

	const Data::T & m_vector;
	Size::T m_pointer;
};

static_assert (TypeTraits::IsInputStream::T <T>::value);
