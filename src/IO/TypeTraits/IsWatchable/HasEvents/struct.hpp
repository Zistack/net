template <typename Watchable,
    typename
#ifndef IO_TypeTraits_IsWatchable_HasEvents_struct_hpp
#define IO_TypeTraits_IsWatchable_HasEvents_struct_hpp
    = void
#endif /* IO_TypeTraits_IsWatchable_HasEvents_struct_hpp */
    >
struct T : std::false_type
{
};

template <typename Watchable>
struct T<Watchable,
    std::enable_if_t<std::is_invocable_r_v<IO::Watchable::Events::T,
        decltype (
            &std::remove_cv_t<std::remove_reference_t<Watchable>>::events),
        const std::remove_cv_t<std::remove_reference_t<Watchable>> *>>>
    : std::true_type
{
};
