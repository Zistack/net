template <typename Query, typename ... Types>
static constexpr bool V = Implementation::T <Query, Types ...>::value;
