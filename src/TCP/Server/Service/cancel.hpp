template <typename Protocol>
void
T<Protocol>::cancel ()
{
	this->shutdown_signal.cancel ();
}
