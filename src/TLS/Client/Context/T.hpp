T::T (IO::Interface::NonblockingInputStream::T & input,
    IO::Interface::NonblockingOutputStream::T & output,
    const Config::T & config) :
    TLS::Context::T (tls_client ()),
    TLS::ConnectableContext::T (input, output),
    TLS::ConfigurableContext::T (config),
    config (config)
{
}
