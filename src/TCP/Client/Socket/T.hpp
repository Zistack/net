T::T (const Config::T & config) :
    TCP::Socket::T (Util::client (config.hostname, config.port))
{
}
