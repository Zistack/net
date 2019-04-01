T::T () : tcp_socket (-1)
{
}

T::T (int tcp_socket, struct tls * tls_context)
:	tcp_socket (tcp_socket), tls_context (tls_context)
{
}

T::T (T && other)
:	tcp_socket (other . tcp_socket),
	tls_context (std::move (other . tls_context))
{
	other . tcp_socket = -1;
}
