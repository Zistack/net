template <typename NonblockingInputStream>
void
T<NonblockingInputStream>::clear ()
{
	this->cancel_signal.clear ();
}
