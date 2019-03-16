template <typename OutputStream,
    typename
#ifndef IO_TypeTraits_IsOutputStream_HasPut_struct_hpp
#define IO_TypeTraits_IsOutputStream_HasPut_struct_hpp
    = void
#endif /* IO_TypeTraits_IsOutputStream_HasPut_struct_hpp */
    >
struct T : std::false_type
{
};

template <typename OutputStream>
struct T<OutputStream,
    std::enable_if_t<std::is_invocable_r_v<void,
        decltype (
            &std::remove_cv_t<std::remove_reference_t<OutputStream>>::put),
        std::remove_cv_t<std::remove_reference_t<OutputStream>> *,
        char>>> : std::true_type
{
};
