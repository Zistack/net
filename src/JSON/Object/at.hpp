Value::T *
T::at (std::string name)
{
	if (this->members.count (name))
		return this->members[name];
	else
		return nullptr;
}
