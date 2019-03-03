struct T
{
	T ();
	T (const char * string);
	T (const std::string & string);
	T (const std::optional<std::string> & string);
	T (const T & other) = default;

	T &
	operator= (const T & other) = default;

	const char *
	cString () const;

	std::string &
	stdString ();

	const std::string &
	stdString () const;

	std::optional<std::string> &
	optional ();

	const std::optional<std::string> &
	optional () const;

	bool
	hasValue () const;

	std::string::size_type
	size () const;

	operator bool () const;

	void
	set (const char * string);

	T &
	operator= (const char * string);

	void
	set (const std::string & string);

	T &
	operator= (const std::string & string);

	void
	set (const std::optional<std::string> & string);

	T &
	operator= (const std::optional<std::string> & string);

	private:
	std::optional<std::string> string;
};
