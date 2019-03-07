template <typename ValueType,
    bool optional,
    const std::string & member_identifier,
    const std::string & description,
    std::optional<ValueType> default_value,
    typename... RemainingMemberTypes>
template <const std::string & identifier, typename>
void
T<Member::T<ValueType, optional, member_identifier, description, default_value>,
    RemainingMemberTypes...>::
    set (const typename MemberType::ValueInterfaceType & value)
{
	this->member.set (value);
}

template <typename ValueType,
    bool optional,
    const std::string & member_identifier,
    const std::string & description,
    std::optional<ValueType> default_value,
    typename... RemainingMemberTypes>
template <const std::string & identifier, typename>
void
T<Member::T<ValueType, optional, member_identifier, description, default_value>,
    RemainingMemberTypes...>::set (typename MemberType::ValueInterfaceType &&
        value)
{
	this->member.set (std::move (value));
}
