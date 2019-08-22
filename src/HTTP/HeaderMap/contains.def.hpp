bool
T::contains (const std::string & field_name) const
{
	return this -> m_map . count (normalize (field_name));
}
