std::string
T::pop (const std::string & field_name)
{
	std::string normalized_field_name = normalize (field_name);

	std::string field_value = this -> m_map . at (normalized_field_name);
	this -> m_map . erase (normalized_field_name);

	return field_value;
}
