template <typename ValueType,
    bool optional,
    const std::string & identifier,
    const std::string & description,
    std::optional<ValueType> default_value>
typename T<ValueType, optional, identifier, description, default_value>::
    ValueInterfaceType
    T<ValueType, optional, identifier, description, default_value>::get () const
{
	if constexpr (optional)
	{
		if (this->value)
		{
			return std::make_optional (this->value.get ());
		}
		else
		{
			return std::nullopt;
		}
	}
	else
	{
		return this->value->get ();
	}
}
