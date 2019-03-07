template <typename ValueType,
    bool optional,
    const std::string & member_identifier,
    const std::string & description,
    const std::optional<ValueType> & default_value,
    typename... RemainingMemberTypes>
template <const std::string & identifier, typename>
typename Member::T<ValueType,
    optional,
    member_identifier,
    description,
    default_value>::ValueInterfaceType
T<Member::T<ValueType, optional, member_identifier, description, default_value>,
    RemainingMemberTypes...>::get () const
{
	if (!this->value)
	{
		throw Failure::SemanticError::T (
		    "Member '" + identifier + "' does not have a value\n");
	}

	return this->member.get ();
}
