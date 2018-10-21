template <class Type>
Type &
T<Type>::value ()
{
	return *this->value_ptr;
}

template <class Type>
const Type &
T<Type>::value () const
{
	return *this->value_ptr;
}
