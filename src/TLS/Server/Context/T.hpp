T::T (const Config::T & config) :
    TLS::Context::T (tls_server ()),
    ConfigurableContext::T (config)
{
}
