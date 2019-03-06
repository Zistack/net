template <const std::string & query, typename... MemberTypes>
struct T;

template <const std::string & query,
    const std::string & identifier,
    typename ValueType,
    const std::string & description,
    bool optional,
    std::optional<ValueType> default_value,
    typename... RemainingMemberTypes>
struct T<query,
    Member::T<identifier, ValueType, description, optional, default_value>,
    RemainingMemberTypes...>
{
	static constexpr const bool value =
	    (query == identifier) || T<query, RemainingMemberTypes...>::value;
};

template <const std::string & query>
struct T<query>
{
	static const constexpr bool value = false;
};
