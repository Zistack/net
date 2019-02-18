T::T (const Config::Value::T & config) :
    T (Util::client (config.getTCPConfig ().getHostname ().cString (),
        config.getTCPConfig ().getPort ().cString (),
        config.makeTLSConfig ().get (),
        config.getServerName ().data ()))
{
}

T::T (int tcp_socket, struct tls * client_context) :
    TLS::ConnectionSocket::T (tcp_socket, client_context)
{
}

T::T (std::pair<int, struct tls *> p) : T (p.first, p.second) {}
