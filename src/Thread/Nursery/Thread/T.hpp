template <class Function, class... Arguments, typename>
T::T (Function && function,
    Arguments &&... arguments,
    Failure::Cancellable::T * cancellable) noexcept :
    cancellable (cancellable),
    thread (std::forward<Function> (function),
        std::forward<Arguments> (arguments)...)
{
}

T::T (std::nullptr_t, Failure::Cancellable::T * cancellable) noexcept :
    cancellable (cancellable)
{
}
