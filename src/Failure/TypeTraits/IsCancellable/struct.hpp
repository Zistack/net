template <typename Cancellable,
    typename
#ifndef Failure_IsCancellable_struct_hpp
#define Failure_IsCancellable_struct_hpp
    = void
#endif /* Failure_IsCancellable_struct_hpp */
    >
struct T : std::false_type
{
};

template <typename Cancellable>
struct T<Cancellable,
    std::enable_if_t<std::is_invocable_r_v<void,
        decltype (
            &std::remove_cv_t<std::remove_reference_t<Cancellable>>::cancel),
        std::remove_cv_t<std::remove_reference_t<Cancellable>> *>>>
    : std::true_type
{
};
