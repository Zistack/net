void
T::insert (const std::string & field_name, const std::string & field_value)
{
	this -> m_map . insert ({normalize (field_name), field_value});
}
