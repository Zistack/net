template <const std::string & member_identifier,
    typename ValueType,
    const std::string & description,
    bool optional,
    std::optional<ValueType> default_value,
    typename... RemainingMemberTypes>
void
T<Member::T<member_identifier, ValueType, description, optional, default_value>,
    RemainingMemberTypes...>::unset (const std::string & identifier)
{
	if (identifier == member_identifier)
	{
		this->member.unset ();
	}
	else
	{
		this->T<RemainingMemberTypes...>::unset (identifier);
	}
}

void
T<>::unset (const std::string & identifier)
{
	throw Failure::SyntaxError::T ("No member named '" + identifier +
	    "' is defined for this section type\n");
}
