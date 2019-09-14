template <typename Type>
constexpr decltype (auto)
launder (typename std::remove_reference_t <Type> & type)
{
	if constexpr (std::is_lvalue_reference_v <Type>) return std::ref (type);
	else return (Type &&) type;
}

template <typename Type>
constexpr decltype (auto)
launder (typename std::remove_reference_t <Type> && type)
{
	if constexpr (std::is_lvalue_reference_v <Type>) return std::ref (type);
	else return (Type &&) type;
}

static_assert (std::is_rvalue_reference_v <decltype (launder <int> (0))>);
static_assert (std::is_same_v <decltype (launder <int &> (0)), std::reference_wrapper <int>>);
static_assert (std::is_rvalue_reference_v <decltype (launder <int &&> (0))>);
