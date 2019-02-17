T::T (const Config::Value::T & config) :
    file_descriptor (Util::server (config.getHostname ().cString (),
        config.getPort ().cString ()))
{
}
