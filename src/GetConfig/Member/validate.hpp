template <const std::string & identifier,
    typename ValueType,
    const std::string & description,
    bool optional,
    std::optional<ValueType> default_value>
void
T<identifier, ValueType, description, optional, default_value>::validate ()
    const
{
	if constexpr (!optional)
	{
		if (!this->value)
		{
			throw Failure::SemanticError::T ("Value is required for member '" +
			    identifier + "' and is not provided\n");
		}
	}
}
