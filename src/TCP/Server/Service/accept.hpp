template <typename Protocol>
void
T<Protocol>::accept (Socket::T & server_socket, Thread::Nursery::T & nursery)
{
	auto connection_protocol = this->server_protocol.make ();

	connection_protocol->prime ();

	std::unique_ptr<Connection::Socket::T> connection_socket =
	    server_socket.accept ();

	nursery.add (*connection_protocol,
	    [connection_protocol (std::move (connection_protocol)),
	        connection_socket (std::move (connection_socket))]() {
		    try
		    {
			    connection_protocol->run (IO::Blocking::InputStream::T (
			                                  connection_socket->reciever ()),
			        IO::Blocking::OutputStream::T (
			            connection_socket->sender ()));
		    }
		    catch (...)
		    {
			    // Log it, which for now means ignore it.
		    }
	    });
}
