template
<
	typename ValueDetails,
	bool optional,
	const std::string & member_identifier,
	const std::string & description,
	const std::optional <typename ValueDetails::Value> & default_value,
	typename ... RemainingMemberTypes
>
struct T
<
	Member::T
	<
		ValueDetails,
		optional,
		member_identifier,
		description,
		default_value
	>,
	RemainingMemberTypes ...
> : T <RemainingMemberTypes ...>
{
	using MemberType = Member::T
	<
		ValueDetails,
		optional,
		member_identifier,
		description,
		default_value
	>;

	static_assert (
		! Contains::T <member_identifier, RemainingMemberTypes ...>::value,
		"Member identifiers must be unique\n"
	);

	T () = default;

	void
	validate () const;

	template <const std::string & identifier>
	decltype (auto)
	value () const;

	template <const std::string & identifier>
	decltype (auto)
	value ();

	~T () = default;

protected:

	template <typename InputStream>
	void
	readFrom (const std::string & identifier, InputStream && input_stream);

	void
	unset (const std::string & identifier);

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream, size_t indentation) const;

	template <typename OutputStream>
	static void
	printHelp
	(
		OutputStream && output_stream,
		size_t columns,
		size_t tabwidth,
		size_t indentation
	);

private:

	MemberType m_member;
};

template <>
struct T <>
{
	T () = default;

	void
	validate () const;

	template <const std::string & identifier>
	void
	value () const;

	~T () = default;

protected:

	template <typename InputStream>
	void
	readFrom (const std::string & identifier, InputStream && input_stream);

	void
	unset (const std::string & identifier);

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream, size_t indentation) const;

	template <typename OutputStream>
	static void
	printHelp
	(
		OutputStream && output_stream,
		size_t columns,
		size_t tabwidth,
		size_t indentation
	);
};
