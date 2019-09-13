template
<
	typename ValueDetails,
	bool optional,
	const std::string & identifier,
	const std::string & description,
	const std::optional <typename ValueDetails::Value> & default_value
>
const typename T
<
	ValueDetails,
	optional,
	identifier,
	description,
	default_value
>::ValueInterface &
T
<
	ValueDetails,
	optional,
	identifier,
	description,
	default_value
>::value () const
{
	if constexpr (optional) return this -> m_value;
	else return * this -> m_value;
}

template
<
	typename ValueDetails,
	bool optional,
	const std::string & identifier,
	const std::string & description,
	const std::optional <typename ValueDetails::Value> & default_value
>
typename T
<
	ValueDetails,
	optional,
	identifier,
	description,
	default_value
>::ValueInterface &
T
<
	ValueDetails,
	optional,
	identifier,
	description,
	default_value
>::value ()
{
	if constexpr (optional) return this -> m_value;
	else return * this -> m_value;
}
