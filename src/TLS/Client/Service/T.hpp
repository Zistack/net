T::T (IO::Interface::Protocol::T & protocol, Config::Value::T & config) :
    TLS::Connection::T (protocol, config.getConnectionConfig ()),
    config (config)
{
}
