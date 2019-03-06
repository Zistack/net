template <const std::string & member_identifier,
    typename ValueType,
    const std::string & description,
    bool optional,
    std::optional<ValueType> default_value,
    typename... RemainingMemberTypes>
void
T<Member::T<member_identifier, ValueType, description, optional, default_value>,
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
