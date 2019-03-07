template <typename ValueType,
    bool optional,
    const std::string & member_identifier,
    const std::string & description,
    const std::optional<ValueType> & default_value,
    typename... RemainingMemberTypes>
template <const std::string & identifier>
/*typename Member::T<ValueType,
    optional,
    member_identifier,
    description,
    default_value>::ValueInterfaceType*/
auto
T<Member::T<ValueType, optional, member_identifier, description, default_value>,
    RemainingMemberTypes...>::get () const
{
	if constexpr (&identifier == &member_identifier)
	{
		return this->member.get ();
	}
	else
	{
		return this->T<RemainingMemberTypes...>::template get<identifier> ();
	}
}

template <const std::string & identifier>
void
T<>::get () const
{
}
