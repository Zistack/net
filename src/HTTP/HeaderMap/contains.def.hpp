bool
T::contains (const std::string & field_name) const
{
	return this -> map . count (normalize (field_name));
}
