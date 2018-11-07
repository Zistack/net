template <class Callable, Callable f>
struct T;

template <class ReturnType,
    class... ArgumentTypes,
    ReturnType (f) (ArgumentTypes...)>
struct T<ReturnType (ArgumentTypes...), f>
{
	ReturnType
	operator() (ArgumentTypes &&... arguments);
};
