T::T (IO::Interface::Protocol::T & connection_protocol,
    std::chrono::milliseconds timeout) :
    TLS::Connection::T (connection_protocol, timeout)
{
}
