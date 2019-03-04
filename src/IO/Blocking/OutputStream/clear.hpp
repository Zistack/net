template <typename NonblockingOutputStream>
void
T<NonblockingOutputStream>::clear ()
{
	this->cancel_signal.clear ();
}
