struct T : MemberType::T
{
	using ValueType = Section::T;

	template <typename Iterable>
	using IsProperIterableType =
	    typename std::is_convertible<decltype (
	                                     *std::declval<Iterable> ().begin ()),
	        MemberSpec::T>;

	template <typename Iterable,
	    typename = typename std::enable_if<
	        IsProperIterableType<Iterable>::value>::type>
	T (Iterable && members);

	std::unique_ptr<MemberType::T>
	clone () const override;

	std::unique_ptr<MemberValue::T>
	readFrom (
	    IO::Interface::PeekableInputStream::T & input_stream) const override;

	void
	writeTo (const MemberValue::T & value,
	    IO::Interface::OutputStream::T & output_stream,
	    size_t indentation) const override;

	std::unique_ptr<ValueType>
	set (const ValueType::InterfaceType & value) const;

	const ValueType::InterfaceType &
	get (const ValueType & value) const;

	void
	printHelp (IO::Interface::OutputStream::T & output_stream,
	    size_t columns,
	    size_t tabwidth,
	    size_t indentation) const;

	~T () = default;

	std::set<MemberSpec::T> members;
};
