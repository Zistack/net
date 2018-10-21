template <class Type>
T<Type>::operator const Type & () const
{
	return this->value ();
}
