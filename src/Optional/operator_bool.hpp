template <class Type>
T<Type>::operator bool () const
{
	return this->hasValue ();
}
