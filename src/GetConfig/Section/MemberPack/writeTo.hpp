template <const std::string & member_identifier,
    typename ValueType,
    const std::string & description,
    bool optional,
    std::optional<ValueType> default_value,
    typename... RemainingMemberTypes>
template <typename OutputStream>
void
T<Member::T<member_identifier, ValueType, description, optional, default_value>,
    RemainingMemberTypes...>::writeTo (OutputStream && output_stream,
    size_t indentation) const
{
	this->member.writeTo (
	    std::forward<OutputStream> (output_stream), indentation);

	this->T<RemainingMemberTypes...>::writeTo (
	    std::forward<OutputStream> (output_stream), indentation);
}

template <typename OutputStream>
void
T<>::writeTo (OutputStream && output_stream, size_t indentation) const
{
}
