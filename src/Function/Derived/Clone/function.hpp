template <class Callable, class ReturnType, class... ArgumentTypes>
std::unique_ptr<Base::T<ReturnType (ArgumentTypes...)>>
T<Callable, true, ReturnType, ArgumentTypes...>::function (
    const Derived::T<Callable, ReturnType, ArgumentTypes...> & derived)
{
	return std::make_unique<
	    Derived::T<Callable, ReturnType, ArgumentTypes...>> (derived.callable);
}

template <class Callable, class ReturnType, class... ArgumentTypes>
std::unique_ptr<Base::T<ReturnType (ArgumentTypes...)>>
T<Callable, false, ReturnType, ArgumentTypes...>::function (
    const Derived::T<Callable, ReturnType, ArgumentTypes...> & derived)
{
	return nullptr;
	// std::make_unique<Derived::T<Callable, ReturnType, ArgumentTypes...>>
	// (nullptr);
}
