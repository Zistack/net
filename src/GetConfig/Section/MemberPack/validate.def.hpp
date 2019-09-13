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
>::validate () const
{
	this -> m_member . validate ();

	this -> T <RemainingMemberTypes ...>::validate ();
}

void
T <>::validate () const
{
}
