template <typename NonblockingInputStream>
bool
T <NonblockingInputStream>::isReady () const
{
	return this -> m_begin != this -> m_end;
}
