T::T (IO::Interface::Protocol::T * protocol,
    std::function<IO::Interface::ClientSocket::T *(void)> newSocket) :
    protocol (protocol),
    newSocket (newSocket)
{
}
