template <class Type>
T<Type>::operator Type & ()
{
	return this->value ();
}
