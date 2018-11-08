template <class ReturnType, class... ArgumentTypes>
T<ReturnType (ArgumentTypes...)> &
T<ReturnType (ArgumentTypes...)>::operator= (const T & other)
{
	this->function = other.function->clone ();

	return *this;
}

template <class ReturnType, class... ArgumentTypes>
T<ReturnType (ArgumentTypes...)> &
T<ReturnType (ArgumentTypes...)>::operator= (T && other)
{
	this->function = std::move (other.function);

	return *this;
}

template <class ReturnType, class... ArgumentTypes>
T<ReturnType (ArgumentTypes...)> & T<ReturnType (ArgumentTypes...)>::operator= (
    std::nullptr_t)
{
	this->function = nullptr;

	return *this;
}
