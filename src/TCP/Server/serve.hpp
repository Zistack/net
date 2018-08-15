void
T::serve (IO::Socket::T socket)
{
	IO::Interface::Protocol::T * protocol = protocol_factory->make ();

	{
		Connection::T connection (*protocol, *this->signal, socket, this->log);

		connection.run ();
	}

	delete protocol;
}
