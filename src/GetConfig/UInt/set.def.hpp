void
T::set (const InterfaceType & value)
{
	this -> value = value;
}

void
T::set (InterfaceType && value)
{
	this -> value = std::move (value);
}
