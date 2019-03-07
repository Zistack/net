template <typename Protocol>
T<Protocol>::T (Protocol server_protocol, const Config::T & config) :
    server_protocol (server_protocol),
    config (config)
{
}
