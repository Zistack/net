T::T (const char * hostname,
    const char * port,
    IO::Interface::OutputStream::T * log,
    IO::Interface::ProtocolFactory::T * protocol_factory) :
    hostname (hostname),
    port (port),
    log (log),
    protocol_factory (protocol_factory)
{
}
