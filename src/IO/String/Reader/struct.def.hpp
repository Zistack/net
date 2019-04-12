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
	const Data::T & string;
	Size::T pointer;

	static_assert (TypeTraits::IsInputStream::T <T>::value);
};
