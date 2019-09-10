std::string
T::pop (const std::string & field_name)
{
	std::string normalized_field_name = Util::normalize (field_name);

	auto it = this -> m_map . find (normalized_field_name);
	std::string field_value = it -> second;
	this -> m_map . erase (it);

	return field_value;
}
