template <class Function, typename>
T::T (Function && function, Failure::Cancellable::T * cancellable) noexcept :
    cancellable (cancellable),
    thread (std::forward<Function> (function))
{
}

T::T (std::nullptr_t, Failure::Cancellable::T * cancellable) noexcept :
    cancellable (cancellable)
{
}
