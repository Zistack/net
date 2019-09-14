template <typename Type>
constexpr decltype (auto)
launder (typename std::remove_reference_t <Type> & type);

template <typename Type>
constexpr decltype (auto)
launder (typename std::remove_reference_t <Type> && type);
