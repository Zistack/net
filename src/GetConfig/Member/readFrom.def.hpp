template
<
	typename ValueType,
	bool optional,
	const std::string & identifier,
	const std::string & description,
	const std::optional <ValueType> & default_value
>
template <typename InputStream>
void
T
<
	ValueType,
	optional,
	identifier,
	description,
	default_value
>::readFrom (InputStream && input_stream)
{
	this -> value . emplace (input_stream);
}
