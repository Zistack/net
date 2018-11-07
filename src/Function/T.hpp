template <class ReturnType, class... ArgumentTypes>
T<ReturnType (ArgumentTypes...)>::T ()
{
}

template <class ReturnType, class... ArgumentTypes>
T<ReturnType (ArgumentTypes...)>::T (const T & other) :
    function (other.function->clone ())
{
}

template <class ReturnType, class... ArgumentTypes>
T<ReturnType (ArgumentTypes...)>::T (T && other) :
    function (std::move (other.function))
{
}

template <class ReturnType, class... ArgumentTypes>
template <class Callable, typename, typename>
T<ReturnType (ArgumentTypes...)>::T (const Callable & callable) :
    function (
        std::make_unique<Derived::T<Callable, ReturnType, ArgumentTypes...>> (
            callable))
{
}

template <class ReturnType, class... ArgumentTypes>
template <class Callable, typename, typename, typename>
T<ReturnType (ArgumentTypes...)>::T (Callable && callable) :
    function (
        std::make_unique<Derived::T<Callable, ReturnType, ArgumentTypes...>> (
            std::move (callable)))
{
}
