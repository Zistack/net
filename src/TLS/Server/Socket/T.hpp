T::T (const Config::T & config) :
    TLS::Socket::T (Util::server (config.hostname, config.port)),
    ConfigurableSocket::T (config),
{
}
