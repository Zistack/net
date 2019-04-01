T::T (int tcp_socket, struct tls * tls_context)
:	Socket::T (tcp_socket, tls_context), spurious_read (false)
{
}

T::T (std::pair <int, struct tls *> p) : T (p . first, p . second)
{
}
