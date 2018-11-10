T::T (Server::Socket::T & server_socket) :
    TCP::Socket::T (newSocket (server_socket))
{
}
