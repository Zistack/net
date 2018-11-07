template <class ReturnType, class... ArgumentTypes>
T<ReturnType (ArgumentTypes...)>::operator bool () const
{
	return (bool) this->function;
}
