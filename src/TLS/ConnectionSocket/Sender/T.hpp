T::T (int tcp_socket,
    struct tls * tls_context,
    Thread::SleepMutex::T & socket_mutex,
    bool & spurious_read) :
    tcp_socket (tcp_socket),
    tls_context (tls_context),
    socket_mutex (socket_mutex),
    spurious_read (spurious_read),
    next (0),
    buffer (new char[BUFFER_SIZE])
{
}
