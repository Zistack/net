template <typename ValueType, const Spec::T & spec>
template <typename MemberType, typename>
void
T<ValueType, spec>::set (const std::string & identifier,
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
