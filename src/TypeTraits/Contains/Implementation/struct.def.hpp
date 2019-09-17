template <typename Query, typename ... RemainingTypes>
struct T <Query, Query, RemainingTypes ...> : std::true_type
{
};

template <typename Query, typename Type, typename ... RemainingTypes>
struct T <Query, Type, RemainingTypes ...> : T <Query, RemainingTypes ...>
{
};

template <typename Query>
struct T <Query> : std::false_type
{
};
