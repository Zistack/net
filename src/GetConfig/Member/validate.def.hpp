template
<
	typename ValueDetails,
	bool optional,
	const std::string & identifier,
	const std::string & description,
	const std::optional <typename ValueDetails::Value> & default_value
>
void
T
<
	ValueDetails,
	optional,
	identifier,
	description,
	default_value
>::validate () const
{
	if constexpr (! optional)
	{
		if (! this -> m_value)
		{
			throw Failure::SemanticError::T
			(
				"Value is required for member '" +
					identifier +
					"' and is not provided\n"
			);
		}
	}
}
