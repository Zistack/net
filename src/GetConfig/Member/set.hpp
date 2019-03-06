template <const std::string & identifier,
    typename ValueType,
    const std::string & description,
    bool optional,
    std::optional<ValueType> default_value>
void
T<identifier, ValueType, description, optional, default_value>::set (
    const ValueInterfaceType & value)
{
	if constexpr (optional)
	{
		if (value)
		{
			this->value.emplace (*value);
		}
		else
		{
			this->value = std::nullopt;
		}
	}
	else
	{
		this->value.emplace (value);
	}
}

template <const std::string & identifier,
    typename ValueType,
    const std::string & description,
    bool optional,
    std::optional<ValueType> default_value>
void
T<identifier, ValueType, description, optional, default_value>::set (
    ValueInterfaceType && value)
{
	if constexpr (optional)
	{
		if (value)
		{
			this->value.emplace (*value);
		}
		else
		{
			this->value = std::nullopt;
		}
	}
	else
	{
		this->value.emplace (std::move (value));
	}
}
