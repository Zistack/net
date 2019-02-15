void
T::set (const InterfaceType & value)
{
	*this = value;
}

template <typename MemberType, typename>
void
T::set (std::string identifier,
    std::optional<typename MemberType::ValueType::InterfaceType> value)
{
	if (!this->members.count (identifier))
	{
		throw Failure::SemanticError::T (
		    "Unrecognized member identifier '" + identifier + "'\n");
	}

	Member::T & member = this->members.at (identifier);

	if (value)
	{
		member.value =
		    dynamic_cast<MemberType> (*member.type).set (value.get ());
	}
	else
	{
		member.value = nullptr;
	}
}
