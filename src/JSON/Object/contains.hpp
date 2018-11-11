bool
T::contains (const std::string & name) const
{
	return (bool) this->members.count (name);
}
