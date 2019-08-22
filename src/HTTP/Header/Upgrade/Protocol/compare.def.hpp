int
T::compare (const T & other) const
{
	int result = this -> m_name . compare (other . m_name);
	if (result) return result;
	else return this -> m_version . compare (other . m_version);
}
