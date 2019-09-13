template
<
	typename ValueDetails,
	bool optional,
	const std::string & identifier,
	const std::string & description,
	const std::optional <typename ValueDetails::Value> & default_value
>
template <typename InputStream>
void
T
<
	ValueDetails,
	optional,
	identifier,
	description,
	default_value
>::readFrom (InputStream && input_stream)
{
	this -> m_value =
		ValueDetails::readFrom (std::forward <InputStream> (input_stream));
}
