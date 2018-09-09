void
T::serve (T * server, IO::Socket::T * socket)
{
	IO::Interface::Protocol::T * protocol = server->protocol_factory.make ();

	{
		Connection::T connection (protocol, socket, server->log);

		server->connections.insert (&connection);

		connection.run ();

		server->connections.remove (&connection);
	}

	delete protocol;
	delete socket;
}
