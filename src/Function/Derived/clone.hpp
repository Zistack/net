template <class Callable, class ReturnType, class... ArgumentTypes>
std::unique_ptr<Base::T<ReturnType (ArgumentTypes...)>>
T<Callable, ReturnType, ArgumentTypes...>::clone () const
{
	return Clone::T<Callable,
	    std::is_copy_constructible<Callable>::value,
	    ReturnType,
	    ArgumentTypes...>::function (*this);
}
