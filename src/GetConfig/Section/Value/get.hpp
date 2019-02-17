template <typename ValueType, const Spec::T & spec>
template <typename MemberType, typename>
std::optional<typename MemberType::MemberValue::InterfaceType>
T<ValueType, spec>::get (const std::string & identifier) const
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

template <typename ValueType, const Spec::T & spec>
const typename T<ValueType, spec>::InterfaceType &
T<ValueType, spec>::get () const
{
	return *this;
}
