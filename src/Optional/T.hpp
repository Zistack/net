template <class Type>
T<Type>::T () : value_ptr (nullptr)
{
}

template <class Type>
T<Type>::T (const Type & value) : value_ptr (new (this->buf) Type (value))
{
}

template <class Type>
T<Type>::T (const T & other) : value_ptr (nullptr)
{
	if (other.value_ptr) this->set (*other.value_ptr);
}
