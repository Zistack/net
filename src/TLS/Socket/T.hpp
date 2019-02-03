T::T (int tcp_socket, struct tls * tls_context) :
    tcp_socket (tcp_socket),
    tls_context (tls_context)
{
}

T::T (std::pair<int, struct tls *> p) : T (p.first, p.second) {}
