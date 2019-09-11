bool
T::isBoolean () const
{
	return std::holds_alternative <Boolean::T> (this -> m_contents);
}
