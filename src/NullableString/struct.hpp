struct T
{
	T ();
	T (const char * string);
	T (const std::string & string);
	T (const T & other) = default;

	T &
	operator= (const T & other) = default;

	const char *
	cString () const;

	operator const char * () const;

	std::string &
	stdString ();

	operator std::string & ();

	const std::string &
	stdString () const;

	operator const std::string & () const;

	bool
	hasValue () const;

	operator bool () const;

	void
	set (const char * string);

	T &
	operator= (const char * string);

	void
	set (const std::string & string);

	T &
	operator= (const std::string & string);

	private:
	std::optional<std::string> string;
};
