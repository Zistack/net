template <class Type>
T<Type>::~T ()
{
	if (this->value_ptr) this->value_ptr->~Type ();
}
