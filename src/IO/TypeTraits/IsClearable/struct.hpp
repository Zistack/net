template <typename Clearable,
    typename
#ifndef IO_TypeTraits_IsClearable_struct_hpp
#define IO_TypeTraits_IsClearable_struct_hpp
    = void
#endif /* IO_TypeTraits_IsClearable_struct_hpp */
    >
struct T : std::false_type
{
};

template <typename Clearable>
struct T<Clearable,
    std::enable_if_t<std::is_invocable_r_v<void,
        decltype (&std::remove_cv_t<std::remove_reference_t<Clearable>>::clear),
        std::remove_cv_t<std::remove_reference_t<Clearable>> *>>>
    : std::true_type
{
};