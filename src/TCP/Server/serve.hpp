void
T::serve (T * server, IO::Socket::T * socket)
{
	IO::Interface::Protocol::T * protocol = server->protocol_factory.make ();

	Connection::T connection (protocol, server->signal, socket, server->log);

	connection.run ();

	delete protocol;
	delete socket;
}
