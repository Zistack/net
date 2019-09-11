template <typename NonblockingOutputStream>
void
T <NonblockingOutputStream>::cancel ()
{
	this -> m_cancel_signal . cancel ();
}
