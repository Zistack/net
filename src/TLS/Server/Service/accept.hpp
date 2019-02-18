void
T::accept (Socket::T & server_socket, Thread::Nursery::T & nursery)
{
	std::unique_ptr<IO::Interface::Protocol::T> connection_protocol =
	    this->server_protocol.make ();

	std::unique_ptr<Connection::Service::T> connection_service =
	    std::make_unique<Connection::Service::T> (
	        *connection_protocol, this->timeout);

	connection_service->prime ();

	std::unique_ptr<Connection::Socket::T> connection_socket =
	    server_socket.accept ();

	nursery.add (*connection_protocol,
	    [connection_protocol (std::move (connection_protocol)),
	        connection_service (std::move (connection_service)),
	        connection_socket (std::move (connection_socket))]() {
		    try
		    {
			    connection_service->run (*connection_socket);
		    }
		    catch (...)
		    {
			    // Log it, which for now means ignore it.
		    }
	    });
}
