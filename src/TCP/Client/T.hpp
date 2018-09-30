T::T (const char * hostname,
    const char * port,
    IO::Interface::OutputStream::T * log,
    IO::Interface::Protocol::T * protocol) :
    hostname (hostname),
    port (port),
    log (log),
    protocol (protocol)
{
}
