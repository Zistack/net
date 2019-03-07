template <typename ValueType,
    bool optional,
    const std::string & identifier,
    const std::string & description,
    std::optional<ValueType> default_value>
void
T<ValueType, optional, identifier, description, default_value>::unset ()
{
	if constexpr (optional)
	{
		this->value = std::nullopt;
	}
	else
	{
		throw Failure::SemanticError::T (
		    "Cannot unsetrequired member '" + identifier + "'\n");
	}
}
