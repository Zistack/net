template <typename Lockable>
T <Lockable>::operator bool () const
{
	return this -> m_state;
}
