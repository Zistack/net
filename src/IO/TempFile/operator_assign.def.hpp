T &
T::operator = (T && other)
{
	this -> m_name = std::move (other . m_name);
	this -> m_file_descriptor = other . m_file_descriptor;

	other . m_file_descriptor = -1;

	return * this;
}
