struct T
{
	T ();

	template <typename InputStream>
	T (InputStream && input_stream);

	T (const std::string & path_string);

	template <class Iterable,
	    typename = typename std::enable_if<
	        std::is_convertible<decltype (*std::declval<Iterable> ().begin ()),
	            std::string>::value>::type>
	T (Iterable && iterable, bool absolute = true);

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream) const;

	std::string
	toString () const;

	~T () = default;

	private:
	template <typename InputStream>
	void
	init (InputStream && input_stream);

	std::list<std::string> segments;
	bool absolute;
};
