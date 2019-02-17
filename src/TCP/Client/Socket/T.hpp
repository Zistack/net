T::T (const Config::Value::T & config) :
    TCP::Socket::T (Util::client (config.getHostname ().cString (),
        config.getPort ().cString ()))
{
}
