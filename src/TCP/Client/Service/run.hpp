template <typename Protocol>
void
T<Protocol>::run ()
{
	Socket::T client_socket (this->config);

	this->protocol.run (
	    IO::Blocking::InputStream::T (client_socket.reciever ()),
	    IO::Blocking::OutputStream::T (client_socket.sender ()));
}
