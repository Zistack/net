template
<
	typename ValueDetails,
	bool optional,
	const std::string & identifier,
	const std::string & description,
	const std::optional <typename ValueDetails::Value> & default_value =
		NULLOPT <typename ValueDetails::Value>
>
struct T;
