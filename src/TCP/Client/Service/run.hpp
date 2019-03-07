template <typename Protocol>
void
T<Protocol>::run ()
{
	Socket::T client_socket (this->config);

	this->protocol.run (client_socket.reciever (), client_socket.sender ());
}
