T::T (IO::Interface::ProtocolFactory::T & protocol_factory,
    Context::T & context,
    uint64_t timeout_ns) :
    protocol_factory (protocol_factory),
    context (context),
    timeout_ns (timeout_ns)
{
}
