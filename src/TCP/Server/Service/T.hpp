template <typename ServerProtocol>
T<ServerProtocol>::T (ServerProtocol server_protocol,
    const Config::T & config) :
    server_protocol (server_protocol),
    config (config)
{
}
