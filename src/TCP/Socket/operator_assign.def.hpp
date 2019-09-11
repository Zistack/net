T &
T::operator = (T && other)
{
	this -> m_file_descriptor = other . m_file_descriptor;

	other . m_file_descriptor = -1;

	return * this;
}
