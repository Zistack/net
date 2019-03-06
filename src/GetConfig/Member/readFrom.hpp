template <const std::string & identifier,
    typename ValueType,
    const std::string & description,
    bool optional,
    std::optional<ValueType> default_value>
template <typename InputStream>
void
T<identifier, ValueType, description, optional, default_value>::readFrom (
    InputStream && input_stream)
{
	this->value.emplace (input_stream);
}
