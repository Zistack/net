template <typename ValueType,
    bool optional,
    const std::string & member_identifier,
    const std::string & description,
    std::optional<ValueType> default_value,
    typename... RemainingMemberTypes>
void
T<Member::T<ValueType, optional, member_identifier, description, default_value>,
    RemainingMemberTypes...>::validate () const
{
	this->member.validate ();

	if ((!optional) && (!this->value))
	{
		throw Failure::SemanticError::T ("Value is required for member '" +
		    member_identifier + "' and is not provided\n");
	}

	this->T<RemainingMemberTypes...>::validate ();
}

void
T<>::validate () const
{
}
