T::T (IO::Interface::Protocol::T * protocol,
    std::chrono::milliseconds timeout,
    Config::T & config) :
    TLS::Protocol::T (protocol, timeout),
    config (config)
{
}
