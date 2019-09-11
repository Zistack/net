bool
T::contains (const std::string & name) const
{
	return (bool) this -> m_members . count (name);
}
