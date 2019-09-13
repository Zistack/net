template
<
	typename ValueDetails,
	bool optional,
	const std::string & identifier,
	const std::string & description,
	const std::optional <typename ValueDetails::Value> & default_value
>
T <ValueDetails, optional, identifier, description, default_value>::T ()
:	m_value (default_value)
{
}
