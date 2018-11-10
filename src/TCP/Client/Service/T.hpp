T::T (IO::Interface::Protocol::T & client_protocol, const Config::T & config) :
    ::Socket::Client::Service::T (client_protocol),
    config (config)
{
}
