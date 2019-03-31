template
<
	typename ValueType,
	bool optional,
	const std::string & identifier,
	const std::string & description,
	const std::optional <ValueType> & default_value
>
void
T
<
	ValueType,
	optional,
	identifier,
	description,
	default_value
>::validate () const
{
	if constexpr (!optional)
	{
		if (! this -> value)
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
