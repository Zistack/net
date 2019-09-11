bool
T::spurious ()
{
	bool spurious_read = this -> m_spurious_read;
	this -> m_spurious_read = false;
	return spurious_read;
}
