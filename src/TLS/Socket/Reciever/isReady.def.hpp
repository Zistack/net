template <typename Interface>
bool
T <Interface>::isReady () const
{
	return this -> m_begin != this -> m_end;
}
