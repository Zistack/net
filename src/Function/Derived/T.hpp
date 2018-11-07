template <class Callable, class ReturnType, class... ArgumentTypes>
T<Callable, ReturnType, ArgumentTypes...>::T (const Callable & callable) :
    callable (callable)
{
}

template <class Callable, class ReturnType, class... ArgumentTypes>
T<Callable, ReturnType, ArgumentTypes...>::T (Callable && callable) :
    callable (std::move (callable))
{
}
