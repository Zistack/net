template <typename ServerProtocol>
void
T <ServerProtocol>::cancel ()
{
	this -> m_shutdown_signal . cancel ();
}
