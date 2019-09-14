template
<
	typename ValueDetails,
	bool optional,
	const std::string & member_identifier,
	const std::string & description,
	const std::optional <typename ValueDetails::Value> & default_value,
	typename ... RemainingMemberTypes
>
void
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
>::unset (const std::string & identifier)
{
	if (identifier == member_identifier)
	{
		this -> m_member . unset ();
	}
	else this -> T <RemainingMemberTypes ...>::unset (identifier);
}

void
T <>::unset (const std::string & identifier)
{
}
