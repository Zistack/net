T::T (int tcp_socket, struct tls * tls_context) :
    Socket::T (tcp_socket, tls_context),
    input_stream (tcp_socket),
    output_stream (tcp_socket)
{
}
