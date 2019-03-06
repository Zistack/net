template <const std::string & identifier,
    typename ValueType,
    const std::string & description,
    bool optional,
    std::optional<ValueType> default_value>
T<identifier, ValueType, description, optional, default_value>::T () :
    value (default_value)
{
}
