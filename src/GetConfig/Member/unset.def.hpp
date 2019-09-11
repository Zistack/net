template
<
	typename ValueType,
	bool optional,
	const std::string & identifier,
	const std::string & description,
	const std::optional <ValueType> & default_value
>
void
T <ValueType, optional, identifier, description, default_value>::unset ()
{
	if constexpr (optional)
	{
		this -> m_value = std::nullopt;
	}
	else
	{
		throw Failure::SemanticError::T
		(
			"Cannot unsetrequired member '" + identifier + "'\n"
		);
	}
}
