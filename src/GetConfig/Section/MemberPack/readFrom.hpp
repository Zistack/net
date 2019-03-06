template <const std::string & member_identifier,
    typename ValueType,
    const std::string & description,
    bool optional,
    std::optional<ValueType> default_value,
    typename... RemainingMemberTypes>
template <typename InputStream>
void
T<Member::T<member_identifier, ValueType, description, optional, default_value>,
    RemainingMemberTypes...>::readFrom (const std::string & identifier,
    InputStream && input_stream)
{
	if (identifier == member_identifier)
	{
		this->member.set (std::forward<InputStream> (input_stream));
	}
	else
	{
		this->T<RemainingMemberTypes...>::set (
		    identifier, std::forward<InputStream> (input_stream));
	}
}

template <typename InputStream>
void
T<>::readFrom (const std::string & identifier, InputStream && input_stream)
{
	throw Failure::SyntaxError::T ("No member named '" + identifier +
	    "' is defined for this section type\n");
}
