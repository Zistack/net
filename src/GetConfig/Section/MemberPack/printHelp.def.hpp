template
<
	typename ValueType,
	bool optional,
	const std::string & member_identifier,
	const std::string & description,
	const std::optional <ValueType> & default_value,
	typename ... RemainingMemberTypes
>
template <typename OutputStream>
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
>::printHelp
(
	OutputStream && output_stream,
	size_t columns,
	size_t tabwidth,
	size_t indentation
)
{
	MemberType::printHelp
	(
		std::forward <OutputStream> (output_stream),
		columns,
		tabwidth,
		indentation
	);

	T <RemainingMemberTypes ...>::printHelp
	(
		std::forward <OutputStream> (output_stream),
		columns,
		tabwidth,
		indentation
	);
}

template <typename OutputStream>
void
T <>::printHelp
(
	OutputStream && output_stream,
	size_t columns,
	size_t tabwidth,
	size_t indentation
)
{
}
