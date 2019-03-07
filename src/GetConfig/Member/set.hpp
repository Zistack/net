template <typename ValueType,
    bool optional,
    const std::string & identifier,
    const std::string & description,
    const std::optional<ValueType> & default_value>
void
T<ValueType, optional, identifier, description, default_value>::set (
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

template <typename ValueType,
    bool optional,
    const std::string & identifier,
    const std::string & description,
    const std::optional<ValueType> & default_value>
void
T<ValueType, optional, identifier, description, default_value>::set (
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
