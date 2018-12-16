struct T
{
	T () = default;

	T (IO::PeekableInputStream::T & input_stream);

	template <class Iterable,
	    typename = typename std::enable_if<
	        std::is_convertible<decltype (*std::declval<Iterable> ().begin ()),
	            std::pair<std::string, std::string>>::value>::type>
	T (const Iterable & iterable);

	bool
	contains (const std::string & field_name) const;

	const std::string &
	at (const std::string & field_name) const;

	std::string
	pop (const std::string & field_name);

	void
	insert (const std::string & field_name, const std::string & field_value);

	void
	remove (const std::string & field_name);

	void
	writeTo (IO::Interface::OutputStream::T & output_stream) const;

	~T () = default;

	private:
	std::unordered_map<std::string, std::string> map;
};
