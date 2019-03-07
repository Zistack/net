template <typename ValueType,
    bool optional,
    const std::string & identifier,
    const std::string & description,
    const std::optional<ValueType> & default_value>
T<ValueType, optional, identifier, description, default_value>::T () :
    value (default_value)
{
}
