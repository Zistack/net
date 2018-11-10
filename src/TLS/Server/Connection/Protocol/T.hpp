T::T (std::unique_ptr<IO::Interface::Protocol::T> connection_protocol,
    std::chrono::milliseconds timeout,
    Server::Context::T & server_context) :
    TLS::Protocol::T (*connection_protocol, timeout),
    connection_protocol (std::move (connection_protocol)),
    server_context (server_context)
{
}
