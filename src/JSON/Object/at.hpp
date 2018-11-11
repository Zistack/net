Value::T *
T::at (const std::string & name) const
{
	if (this->contains (name))
		return this->members.at (name).get ();
	else
		return nullptr;
}
