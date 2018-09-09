T::~T ()
{
	delete shutdown_signal;
	delete server_socket;
}
