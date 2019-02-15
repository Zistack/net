struct T
{
	template <typename Iterable>
	using IsProperIterableType =
	    typename std::is_convertible<decltype (
	                                     *std::declval<Iterable> ().begin ()),
	        MemberSpec::T>;

	template <typename Iterable,
	    typename = typename std::enable_if<
	        IsProperIterableType<Iterable>::value>::type>
	T (Iterable && members);

	void
	printHelp (IO::Interface::OutputStream::T & output_stream,
	    size_t columns,
	    size_t tabwidth,
	    size_t indentation) const;

	~T () = default;

	std::set<MemberSpec::T> members;
};
