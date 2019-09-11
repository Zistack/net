bool
T::isArray () const
{
	return std::holds_alternative <Array::T> (this -> m_contents);
}
