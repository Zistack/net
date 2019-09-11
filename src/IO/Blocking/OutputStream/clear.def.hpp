template <typename NonblockingOutputStream>
void
T <NonblockingOutputStream>::clear ()
{
	this -> m_cancel_signal . clear ();
}
