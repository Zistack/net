template <const std::string & member_identifier,
    typename ValueType,
    const std::string & description,
    bool optional,
    std::optional<ValueType> default_value,
    typename... RemainingMemberTypes>
template <const std::string & identifier, typename>
void
T<Member::T<member_identifier, ValueType, description, optional, default_value>,
    RemainingMemberTypes...>::
    set (const typename MemberType::ValueInterfaceType & value)
{
	this->member.set (value);
}

template <const std::string & member_identifier,
    typename ValueType,
    const std::string & description,
    bool optional,
    std::optional<ValueType> default_value,
    typename... RemainingMemberTypes>
template <const std::string & identifier, typename>
void
T<Member::T<member_identifier, ValueType, description, optional, default_value>,
    RemainingMemberTypes...>::set (typename MemberType::ValueInterfaceType &&
        value)
{
	this->member.set (std::move (value));
}
