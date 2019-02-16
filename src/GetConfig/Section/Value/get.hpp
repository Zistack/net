template <typename MemberType, typename>
std::optional<typename MemberType::MemberValue::InterfaceType>
T::get (std::string identifier) const
{
	if (!this->members.count (identifier))
	{
		throw Failure::SemanticError::T (
		    "Unrecognized member identifier '" + identifier + "'\n");
	}

	const Member::T & member = this->members.at (identifier);

	if (member.value)
	{
		return std::make_optional (
		    dynamic_cast<MemberType> (*member.type).get (*member.value));
	}
	else
	{
		return std::nullopt;
	}
}

const T::InterfaceType &
T::get () const
{
	return *this;
}
