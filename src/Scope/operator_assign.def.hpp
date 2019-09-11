template <typename Scopable>
T <Scopable> &
T <Scopable>::operator = (T && other)
{
	if (this -> m_scopable) this -> m_scopable -> close ();

	this -> m_scopable = other . m_scopable;
	other . m_scopable = nullptr;

	return * this;
}
