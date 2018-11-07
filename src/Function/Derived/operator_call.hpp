template <class Callable, class ReturnType, class... ArgumentTypes>
ReturnType
T<Callable, ReturnType, ArgumentTypes...>::operator() (
    ArgumentTypes &&... arguments)
{
	return this->callable (arguments...);
}
