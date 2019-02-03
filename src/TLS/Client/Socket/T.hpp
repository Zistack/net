T::T (const Config::T & config) :
    TLS::Socket::T (
        Util::client (config.hostname, config.port, config.servername)),
    TLS::ConfigurableSocket::T (config)
{
}
