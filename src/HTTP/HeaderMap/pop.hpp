std::string
T::pop (const std::string & field_name)
{
	std::string field_value = this->map.at (field_name);
	this->map.erase (field_name);

	return field_value;
}
