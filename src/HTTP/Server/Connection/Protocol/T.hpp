T::T (std::chrono::milliseconds input_timeout,
    std::chrono::milliseconds output_timeout,
    Responder::T & responder) :
    FIFOProtocol::Server::Connection::Protocol::T<Request::T, Response::T> (
        input_timeout,
        output_timeout),
    responder (responder)
{
}
