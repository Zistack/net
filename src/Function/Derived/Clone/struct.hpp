template <class Callable,
    bool is_copyable,
    class ReturnType,
    class... ArgumentTypes>
struct T;

template <class Callable, class ReturnType, class... ArgumentTypes>
struct T<Callable, true, ReturnType, ArgumentTypes...>
{
	static std::unique_ptr<Base::T<ReturnType (ArgumentTypes...)>>
	function (
	    const Derived::T<Callable, ReturnType, ArgumentTypes...> & derived);
};

template <class Callable, class ReturnType, class... ArgumentTypes>
struct T<Callable, false, ReturnType, ArgumentTypes...>
{
	static std::unique_ptr<Base::T<ReturnType (ArgumentTypes...)>>
	function (
	    const Derived::T<Callable, ReturnType, ArgumentTypes...> & derived);
};
