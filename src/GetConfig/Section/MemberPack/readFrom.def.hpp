template
<
	typename ValueType,
	bool optional,
	const std::string & member_identifier,
	const std::string & description,
	const std::optional <ValueType> & default_value,
	typename ... RemainingMemberTypes
>
template <typename InputStream>
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
>::readFrom (const std::string & identifier, InputStream && input_stream)
{
	if (identifier == member_identifier)
	{
		this -> m_member . set (std::forward <InputStream> (input_stream));
	}
	else
	{
		this -> T <RemainingMemberTypes ...>::set
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
