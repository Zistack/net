template <typename NonblockingOutputStream>
void
T<NonblockingOutputStream>::cancel ()
{
	this->cancel_signal.cancel ();
}
