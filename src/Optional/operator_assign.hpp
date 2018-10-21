template <class Type>
T<Type> &
T<Type>::operator= (const T & other)
{
	if (this->value_ptr)
	{
		if (other.value_ptr)
		{
			*this->value_ptr = *other.value_ptr;
		}
		else
		{
			this->reset ();
		}
	}
	else
	{
		if (other.value_ptr)
		{
			this->set (*other.value_ptr);
		}
	}
	return *this;
}

template <class Type>
T<Type> &
T<Type>::operator= (const Type & value)
{
	this->set (value);
	return *this;
}
