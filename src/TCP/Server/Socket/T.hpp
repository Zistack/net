T::T (const Config::T & config) :
    file_descriptor (Util::server (config.getHostname ().cString (),
        config.getPort ().cString ()))
{
}
