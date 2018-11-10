template <class ReturnType,
    class... ArgumentTypes,
    ReturnType (f) (ArgumentTypes...)>
ReturnType
T<ReturnType (ArgumentTypes...), f>::operator() (ArgumentTypes... arguments)
{
	return f (arguments...);
}
