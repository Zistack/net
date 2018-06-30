serve (IO::Socket::T * socket)
{
	IO::Interface::Protocol::T * protocol = protocol_factory.make ();

	Connection::T * connection = new Connection::T (protocol, signal, socket, log);

	connection -> run ();

	delete connection;

	delete protocol;

	delete socket ();
}
