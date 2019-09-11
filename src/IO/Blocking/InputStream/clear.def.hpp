template <typename NonblockingInputStream>
void
T <NonblockingInputStream>::clear ()
{
	this -> m_cancel_signal . clear ();
}
