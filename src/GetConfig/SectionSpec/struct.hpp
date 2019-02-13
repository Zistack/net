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
	T (const Iterable && members);

	template <typename Iterable,
	    typename = typename std::enable_if<
	        IsProperIterableType<Iterable>::value>::type>
	T (Iterable && members);

	bool
	contains (const std::string & identifer) const;

	const MemberSpec::T &
	at (const std::string & identifier) const;

	void
	printHelp (IO::Interface::OutputStream::T & output_stream);

	~T () = default;

	std::set<MemberSpec::T> members;
	std::unordered_map<std::string, const MemberSpec::T &> member_map;
};
