template <typename... MemberTypes>
struct T;

template <const std::string & member_identifier,
    typename ValueType,
    const std::string & description,
    bool optional,
    std::optional<ValueType> default_value,
    typename... RemainingMemberTypes>
struct T<
    Member::
        T<member_identifier, ValueType, description, optional, default_value>,
    RemainingMemberTypes...> : T<RemainingMemberTypes...>
{
	using MemberType = Member::
	    T<member_identifier, ValueType, description, optional, default_value>;

	static_assert (
	    !Contains::T<member_identifier, RemainingMemberTypes...>::value,
	    "Member identifiers must be unique\n");

	T () = default;

	template <const std::string & identifier,
	    typename =
	        typename std::enable_if<identifier == member_identifier>::type>
	typename MemberType::ValueInterfaceType
	get () const;

	template <const std::string & identifier,
	    typename =
	        typename std::enable_if<identifier == member_identifier>::type>
	void
	set (const typename MemberType::ValueInterfaceType & value);

	template <const std::string & identifier,
	    typename =
	        typename std::enable_if<identifier == member_identifier>::type>
	void
	set (typename MemberType::ValueInterfaceType && value);

	~T () = default;

	protected:
	template <typename InputStream>
	void
	readFrom (const std::string & identifier, InputStream && input_stream);

	void
	unset (const std::string & identifier);

	void
	validate () const;

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream, size_t indentation) const;

	template <typename OutputStream>
	static void
	printHelp (OutputStream && output_stream,
	    size_t columns,
	    size_t tabwidth,
	    size_t indentation);

	private:
	MemberType member;
};

template <>
struct T<>
{
	T () = default;

	~T () = default;

	protected:
	template <typename InputStream>
	void
	readFrom (const std::string & identifier, InputStream && input_stream);

	void
	unset (const std::string & identifier);

	void
	validate () const;

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream, size_t indentation) const;

	template <typename OutputStream>
	static void
	printHelp (OutputStream && output_stream,
	    size_t columns,
	    size_t tabwidth,
	    size_t indentation);
};
