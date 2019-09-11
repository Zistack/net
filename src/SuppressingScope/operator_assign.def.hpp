template <typename Scopable>
T <Scopable> &
T <Scopable>::operator = (T && other)
{
	if (this -> m_scopable)
	{
		this -> m_exception_store -> tryStore
		(
			[this] () { this -> m_scopable -> close (); }
		);
	}

	this -> m_scopable = other . m_scopable;
	this -> m_exception_store = other . m_exception_store;
	other . m_scopable = nullptr;
	other . m_exception_store = nullptr;

	return * this;
}
