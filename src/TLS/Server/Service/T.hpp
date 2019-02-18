T::T (IO::Interface::Server::Protocol::T & server_protocol,
    std::chrono::milliseconds timeout,
    Config::Value::T & config) :
    server_protocol (server_protocol),
    timeout (timeout),
    config (config)
{
}
