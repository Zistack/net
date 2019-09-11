template <typename NonblockingInputStream>
void
T <NonblockingInputStream>::cancel ()
{
	this -> m_cancel_signal . cancel ();
}
