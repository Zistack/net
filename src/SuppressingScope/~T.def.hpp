template <typename Scopable>
T <Scopable>::~T ()
{
	if (this -> m_scopable)
	{
		this -> m_exception_store -> tryStore
		(
			[this] () { this -> m_scopable -> close (); }
		);
	}
}
