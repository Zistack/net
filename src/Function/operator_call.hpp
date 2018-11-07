template <class ReturnType, class... ArgumentTypes>
ReturnType
T<ReturnType (ArgumentTypes...)>::operator() (ArgumentTypes &&... arguments)
{
	if (this->function)
		return this->function->operator() (arguments...);
	else
		throw Failure::Error::T ("Cannot call a null function\n");
}
