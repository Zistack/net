template <typename Protocol,
    typename
#ifndef IO_TypeTraits_IsProtocol_HasPrime_struct_hpp
#define IO_TypeTraits_IsProtocol_HasPrime_struct_hpp
    = void
#endif /* IO_TypeTraits_IsProtocol_HasPrime_struct_hpp */
    >
struct T : std::false_type
{
};

template <typename Protocol>
struct T<Protocol,
    std::enable_if_t<std::is_invocable_r_v<void,
        decltype (&std::remove_cv_t<std::remove_reference_t<Protocol>>::prime),
        std::remove_cv_t<std::remove_reference_t<Protocol>> *>>>
    : std::true_type
{
};
