T::T (IO::Interface::Protocol::T & protocol,
    std::chrono::milliseconds timeout,
    Config::Value::T & config) :
    TLS::Connection::T (protocol, timeout),
    config (config)
{
}
