T::T (IO::Interface::Protocol::T * protocol,
    std::chrono::milliseconds timeout,
    Server::Context::T & server_context) :
    TLS::Protocol::T (protocol, timeout),
    server_context (server_context)
{
}
