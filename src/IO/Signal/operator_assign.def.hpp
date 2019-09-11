T &
T::operator = (T && other)
{
	if (this -> m_file_descriptor != -1) close (this -> m_file_descriptor);

	this -> m_file_descriptor = other . m_file_descriptor;
	other . m_file_descriptor = -1;

	return * this;
}
