template
<
	typename ValueType,
	bool optional,
	const std::string & member_identifier,
	const std::string & description,
	const std::optional <ValueType> & default_value,
	typename ... RemainingMemberTypes
>
template <const std::string & identifier, typename Value>
void
T
<
	Member::T
	<
		ValueType,
		optional,
		member_identifier,
		description,
		default_value
	>,
	RemainingMemberTypes ...
>::set (Value && value)
{
	if constexpr (& identifier == & member_identifier)
	{
		this -> member . set (std::forward <Value> (value));
	}
	else
	{
		this -> T <RemainingMemberTypes ...>::set <identifier>
		(
			std::forward <Value> (value)
		);
	}
}

template <const std::string & identifier, typename Value>
void
set (Value && value)
{
}
