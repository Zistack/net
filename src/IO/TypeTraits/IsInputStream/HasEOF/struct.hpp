template <typename InputStream,
    typename
#ifndef IO_TypeTraits_IsInputStream_HasEOF_struct_hpp
#define IO_TypeTraits_IsInputStream_HasEOF_struct_hpp
    = void
#endif /* IO_TypeTraits_IsInputStream_HasEOF_struct_hpp */
    >
struct T : std::false_type
{
};

template <typename InputStream>
struct T<InputStream,
    std::enable_if_t<std::is_invocable_r_v<bool,
        decltype (&std::remove_cv_t<std::remove_reference_t<InputStream>>::eof),
        std::remove_cv_t<std::remove_reference_t<InputStream>> *>>>
    : std::true_type
{
};
