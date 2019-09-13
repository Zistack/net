template
<
	typename ValueDetails,
	bool optional,
	const std::string & member_identifier,
	const std::string & description,
	const std::optional <typename ValueDetails::Value> & default_value,
	typename ... RemainingMemberTypes
>
template <const std::string & identifier>
const auto &
T
<
	Member::T
	<
		ValueDetails,
		optional,
		member_identifier,
		description,
		default_value
	>,
	RemainingMemberTypes ...
>::value () const
{
	if constexpr (& identifier == & member_identifier)
	{
		return this -> m_member . value ();
	}
	else
	{
		return this -> T <RemainingMemberTypes ...>::template value <identifier> ();
	}
}

template
<
	typename ValueDetails,
	bool optional,
	const std::string & member_identifier,
	const std::string & description,
	const std::optional <typename ValueDetails::Value> & default_value,
	typename ... RemainingMemberTypes
>
template <const std::string & identifier>
auto &
T
<
	Member::T
	<
		ValueDetails,
		optional,
		member_identifier,
		description,
		default_value
	>,
	RemainingMemberTypes ...
>::value ()
{
	if constexpr (& identifier == & member_identifier)
	{
		return this -> m_member . value ();
	}
	else
	{
		return this -> T <RemainingMemberTypes ...>::template value <identifier> ();
	}
}

template <const std::string & identifier>
void
T <>::value () const
{
}

