template
<
	typename ValueDetails,
	bool optional,
	const std::string & identifier,
	const std::string & description,
	const std::optional <typename ValueDetails::Value> & default_value
>
void
T <ValueDetails, optional, identifier, description, default_value>::unset ()
{
	if constexpr (optional) this -> m_value = std::nullopt;
	else
	{
		throw Failure::SemanticError::T
		(
			"Value is required for member '" +
				identifier +
				"' and cannot be unset\n"
		);
	}
}
