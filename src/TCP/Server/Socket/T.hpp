T::T (const Config::T & config) :
    file_descriptor (Util::server (config.hostname, config.port))
{
}
