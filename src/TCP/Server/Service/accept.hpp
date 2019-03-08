template <typename ServerProtocol>
void
T<ServerProtocol>::accept (Socket::T & server_socket,
    Thread::Nursery::T & nursery)
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
			    IO::Blocking::InputStream::T input_stream (
			        connection_socket->reciever ());
			    IO::Blocking::OutputStream::T output_stream (
			        connection_socket->sender ());

			    connection_protocol->run (input_stream, output_stream);
		    }
		    catch (...)
		    {
			    // Log it, which for now means ignore it.
		    }
	    });
}
