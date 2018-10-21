template <class Type>
struct T
{
	T ();
	T (const Type & value);
	T (const T & other);

	T &
	operator= (const T & other);

	void
	set (const Type & value);

	T &
	operator= (const Type & value);

	bool
	hasValue () const;

	operator bool () const;

	Type &
	value ();

	operator Type & ();

	const Type &
	value () const;

	operator const Type & () const;

	void
	reset ();

	~T ();

	private:
	char buf[sizeof (Type)];
	Type * value_ptr;
};
