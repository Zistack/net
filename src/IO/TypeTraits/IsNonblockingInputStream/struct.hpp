template <typename NonblockingInputStream,
    typename
#ifndef IO_TypeTraits_IsNonblockingInputStream_struct_hpp
#define IO_TypeTraits_IsNonblockingInputStream_struct_hpp
    = void
#endif /* IO_TypeTraits_IsNonblockingInputStream_struct_hpp */
    >
struct T : std::false_type
{
};

template <typename NonblockingInputStream>
struct T<NonblockingInputStream,
    std::enable_if_t<std::is_invocable_r_v<size_t,
        decltype (&std::remove_cv_t<
                  std::remove_reference_t<NonblockingInputStream>>::read),
        std::remove_cv_t<std::remove_reference_t<NonblockingInputStream>> *,
        char *,
        size_t>>> : std::true_type
{
};
