template
<
	typename ValueDetails,
	bool optional,
	const std::string & member_identifier,
	const std::string & description,
	const std::optional <typename ValueDetails::Value> & default_value,
	typename ... RemainingMemberTypes
>
template <typename OutputStream>
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
>::writeTo (OutputStream && output_stream, size_t indentation) const
{
	this -> m_member . writeTo
	(
		std::forward <OutputStream> (output_stream),
		indentation
	);

	this -> T <RemainingMemberTypes ...>::writeTo
	(
		std::forward <OutputStream> (output_stream),
		indentation
	);
}

template <typename OutputStream>
void
T <>::writeTo (OutputStream && output_stream, size_t indentation) const
{
}
