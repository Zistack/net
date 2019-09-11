void
T::set (const InterfaceType & value)
{
	this -> m_value = value;
}

void
T::set (InterfaceType && value)
{
	this -> m_value = std::move (value);
}
