template <class Function, class Cancel, typename>
T::T (Function && function, Cancel && cancel) :
    c (std::forward<Cancel> (cancel)),
    thread (std::forward<Function> (function))
{
}

template <class Cancel>
T::T (std::nullptr_t, Cancel && cancel) : c (std::forward<Cancel> (cancel))
{
}
