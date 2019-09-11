uint64_t
T::length () const
{
	if (this -> m_status_code == 1005) return 0;

	if (this -> m_reason)
	{
		return
			sizeof (this -> m_status_code) +
			this -> m_reason . stdString () . size ();
	}

	return sizeof (this -> m_status_code);
}
