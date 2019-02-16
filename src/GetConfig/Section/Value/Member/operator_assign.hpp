T &
T::operator= (const T & other)
{
	this->optional = other.optional;
	this->type = other.type->clone ();
	this->value = other.value ? other.value->clone () : nullptr;

	return *this;
}
