template <const std::string & identifier,
    typename ValueType,
    const std::string & description,
    bool optional,
    std::optional<ValueType> default_value>
void
T<identifier, ValueType, description, optional, default_value>::unset ()
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
