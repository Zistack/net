template <class Callable, Callable f>
struct T
{
	template <class... Args>
	typename ReturnType::T<Callable>::Type
	operator() (Args &&... args);
};
