template
<
	typename ValueDetails,
	bool optional,
	const std::string & member_identifier,
	const std::string & description,
	const std::optional <typename ValueDetails::Value> & default_value,
	typename ... RemainingMemberTypes
>
template <typename InputStream>
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
>::readFrom (const std::string & identifier, InputStream && input_stream)
{
	if (identifier == member_identifier)
	{
		this -> m_member . readFrom (std::forward <InputStream> (input_stream));
	}
	else
	{
		this -> T <RemainingMemberTypes ...>::readFrom
		(
			identifier,
			std::forward <InputStream> (input_stream)
		);
	}
}

template <typename InputStream>
void
T <>::readFrom (const std::string & identifier, InputStream && input_stream)
{
	throw Failure::SyntaxError::T
	(
		"No member named '" +
			identifier +
			"' is defined for this section type\n"
	);
}
