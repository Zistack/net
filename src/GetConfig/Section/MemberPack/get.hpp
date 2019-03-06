template <const std::string & member_identifier,
    typename ValueType,
    const std::string & description,
    bool optional,
    std::optional<ValueType> default_value,
    typename... RemainingMemberTypes>
template <const std::string & identifier, typename>
typename Member::T<member_identifier,
    ValueType,
    description,
    optional,
    default_value>::ValueInterfaceType
T<Member::T<member_identifier, ValueType, description, optional, default_value>,
    RemainingMemberTypes...>::get () const
{
	if (!this->value)
	{
		throw Failure::SemanticError::T (
		    "Member '" + identifier + "' does not have a value\n");
	}

	return this->member.get ();
}
