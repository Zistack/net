T::T (const Config::Value::T & config) :
    TLS::Socket::T (std::make_from_tuple<TLS::Socket::T> (
        Util::server (config.getTCPConfig ().getHostname ().cString (),
            config.getTCPConfig ().getPort ().cString (),
            config.makeTLSConfig ().get ())))
{
}
