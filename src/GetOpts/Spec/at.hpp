const OptionSpec::T &
T::at (const std::string & option_name) const
{
	return this->long_map.at (option_name);
}

const OptionSpec::T &
T::at (char option_name) const
{
	return this->short_map.at (option_name);
}
