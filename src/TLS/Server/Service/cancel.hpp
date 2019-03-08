template <typename ServerProtocol>
void
T<ServerProtocol>::cancel ()
{
	this->shutdown_signal.cancel ();
}
