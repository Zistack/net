void
T::run ()
{
	Socket::T client_socket (this->config);

	this->protocol.run (
	    client_socket.inputStream (), client_socket.outputStream ());
}
