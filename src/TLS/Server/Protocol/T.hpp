T::T (IO::Interface::Server::Protocol::T & server_protocol,
    std::chrono::milliseconds timeout,
    Config::T & config) :
    server_protocol (server_protocol),
    timeout (timeout),
    context (config)
{
}
