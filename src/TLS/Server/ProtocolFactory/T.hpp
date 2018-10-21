T::T (IO::Interface::ProtocolFactory::T * protocol_factory,
    std::chrono::milliseconds timeout,
    Config::T & config) :
    protocol_factory (protocol_factory),
    timeout (timeout),
    context (config)
{
}
