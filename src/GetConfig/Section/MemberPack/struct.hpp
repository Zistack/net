template <typename... MemberTypes>
struct T;

template <typename ValueType,
    bool optional,
    const std::string & member_identifier,
    const std::string & description,
    const std::optional<ValueType> & default_value,
    typename... RemainingMemberTypes>
struct T<
    Member::
        T<ValueType, optional, member_identifier, description, default_value>,
    RemainingMemberTypes...> : T<RemainingMemberTypes...>
{
	using MemberType = Member::
	    T<ValueType, optional, member_identifier, description, default_value>;

	static_assert (
	    !Contains::T<member_identifier, RemainingMemberTypes...>::value,
	    "Member identifiers must be unique\n");

	T () = default;

	template <const std::string & identifier>
	auto
	get () const;

	template <const std::string & identifier, typename Value>
	void
	set (Value && value);

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

	template <const std::string & identifier>
	void
	get () const;

	template <const std::string & identifier, typename Value>
	void
	set (Value && value);

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
