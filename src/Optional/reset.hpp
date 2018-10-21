template <class Type>
void
T<Type>::reset ()
{
	if (this->value_ptr)
	{
		this->value_ptr->~Type ();
		this->value_ptr = nullptr;
	}
}
