T::T (IO::Interface::Protocol::T & protocol, const Config::Value::T & config) :
    protocol (protocol),
    timeout (config.getTimeout ()),
    buffer_size (config.getBufferSize ()),
    spurious_read (false)
{
}
