template <typename NonblockingInputStream>
void
T <NonblockingInputStream>::cancel ()
{
	this -> cancel_signal . cancel ();
}
