template <class Type>
void
T<Type>::set (const Type & value)
{
	if (this->value_ptr)
		*this->value_ptr = value;
	else
		this->value_ptr = new (this->buf) Type (value);
}
