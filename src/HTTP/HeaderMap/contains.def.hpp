bool
T::contains (const std::string & field_name) const
{
	return this -> m_map . count (Util::normalize (field_name));
}
