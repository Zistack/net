bool
T::contains (const std::string & option_name) const
{
	return this->long_map.count (option_name);
}

bool
T::contains (char option_name) const
{
	return this->short_map.count (option_name);
}
