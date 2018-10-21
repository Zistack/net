template <class Callable, Callable f>
template <class... Args>
typename ReturnType::T<Callable>::Type
T<Callable, f>::operator() (Args &&... args)
{
	return f (args...);
}
