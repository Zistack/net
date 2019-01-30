T::T (Server::Socket::T & server_socket) :
    TCP::Socket::T (Util::accept (server_socket.fileDescriptor ()))
{
}
