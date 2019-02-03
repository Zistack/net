void
T::run ()
{
	Socket::T client_socket (this->config);

	this->run (client_socket);
}
