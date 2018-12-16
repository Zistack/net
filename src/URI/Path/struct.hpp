struct T
{
	T ();

	T (IO::Interface::PeekableInputStream::T & input_stream);

	T (const std::string & path_string);

	template <class Iterable,
	    typename = typename std::enable_if<
	        std::is_convertible<decltype (*std::declval<Iterable> ().begin ()),
	            std::string>::value>::type>
	T (Iterable && iterable, bool absolute = true);

	std::string
	toString () const;

	~T () = default;

	private:
	void
	init (IO::Interface::PeekableInputStream::T & input_stream);

	std::list<std::string> segments;
	bool absolute;
};
