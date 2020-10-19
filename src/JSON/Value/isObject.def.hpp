bool
T::isObject () const
{
	return std::holds_alternative <Object::T> (this -> m_contents);
}
