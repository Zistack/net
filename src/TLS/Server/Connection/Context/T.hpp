T::T (Server::Context::T & server_context,
    IO::Interface::NonblockingInputStream::T & input,
    IO::Interface::NonblockingOutputStream::T & output,
    IO::Signal::T & signal) :
    TLS::Context::T (server_context.accept (input, output)),
    TLS::ConnectableContext::T (input, output)
{
	this->handshake (signal);
}
