T::T (const Config::T & config) :
    ConnectionSocket::T (
        Util::client (config.getTCPConfig ().getHostname ().cString (),
            config.getTCPConfig ().getPort ().cString (),
            config.makeTLSConfig ().get (),
            config.getServerName ().data ()))
{
}
