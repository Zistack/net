template
<
	const std::string & query,
	typename ValueType,
	bool optional,
	const std::string & identifier,
	const std::string & description,
	const std::optional <ValueType> & default_value,
	typename ... RemainingMemberTypes
>
struct T
<
	query,
	Member::T <ValueType, optional, identifier, description, default_value>,
	RemainingMemberTypes ...
>
{
	static constexpr const bool value =
	    (& query == & identifier) || T <query, RemainingMemberTypes ...>::value;
};

template <const std::string & query>
struct T <query>
{
	static const constexpr bool value = false;
};
