template <const std::string & identifier,
    typename ValueType,
    const std::string & description,
    bool optional,
    std::optional<ValueType> default_value>
typename T<identifier, ValueType, description, optional, default_value>::
    ValueInterfaceType
    T<identifier, ValueType, description, optional, default_value>::get () const
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
