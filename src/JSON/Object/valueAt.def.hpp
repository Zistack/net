const Value::T &
T::valueAt (const std::string & name) const
{
	return * this -> m_members . at (name);
}

Value::T &
T::valueAt (const std::string & name)
{
	return * this -> m_members . at (name);
}
