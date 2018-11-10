T::T (IO::Interface::Server::Protocol::T & server_protocol,
    const Config::T & config) :
    ::Socket::Server::Service::T (server_protocol),
    config (config)
{
}
