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

	std::string &
	stdString ();

	const std::string &
	stdString () const;

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
