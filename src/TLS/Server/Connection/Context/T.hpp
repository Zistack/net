T::T (Server::Context::T & server_context,
    IO::Interface::NonblockingInputStream::T & input,
    IO::Interface::NonblockingOutputStream::T & output) :
    TLS::Context::T (server_context.newConnection (input, output)),
    TLS::ConnectableContext::T (input, output)
{
}
