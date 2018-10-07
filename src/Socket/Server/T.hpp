T::T (IO::Interface::ProtocolFactory::T * protocol_factory,
    std::function<IO::Interface::ServerSocket::T *(void)> newSocket) :
    protocol_factory (protocol_factory),
    newSocket (newSocket)
{
}
